
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// yushu.c, 玉鼠精
// created by mes, updated 6-20-97 pickle
// updated again by pickle on 9-2-97, to open her menpai

/************************************************************/

// declarations and variables

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"
   string ask_mieyao();
   string ask_cancel();
string say_key();
void punish_player(object me);
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name("玉鼠精", ({"yu shu","yushu", "shu", "monster"}));
    set_weight(1000000);
  set("gender", "女性" );
  set("age", 23);
  set("long", 
"她就是这无底洞的洞主了。她从修道成人行以来，吃人无数，\n"
"也不知为什么玉皇还未曾派兵来围剿。听说她在天宫有亲，也\n"
"不知真假。\n");
  set("title", "地涌夫人");
  set("combat_exp", 61500000);
  set("attitude", "heroic");
  create_family("陷空山无底洞", 1, "弟子");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set_skill("unarmed", 150);
  set_skill("dodge", 180);
  set_skill("parry", 160);
 
  set("per", 50);
  set("max_qi", 2500);
  set("max_jing", 2500);
  set("neili", 3800);
  set("max_neili", 2000);
  set("force_factor", 50);
  set("neili",3000);
  set("max_neili", 3000);
  set("mana_factor", 50);
  set("inquiry",([
"斗佛" : (: ask_mieyao :),
       "key": (: say_key :),
       "钥匙": (: say_key :),
       "name": "老娘就是这无底洞的开山祖师！",
       "here": "这里就是陷空山无底洞！就算你调十万天兵来也奈何我不得！",
       "rumors": "老娘刚刚抓住一个和尚。看来马上就有新鲜人肉吃了。",
       "人肉包子": "混帐！饿了不会去找厨子？",
       "和尚": "嘿嘿，眼下正饿着他呢。等他肠子干净了就可以蒸熟了吃了。\n"
          "不过也该派人去看看他了。说不定他已经饿死了。",
       "看看": "要看看也行，就是不知道我把钥匙放哪儿了。",
       ]));

  setup();
    initlvl((650+random(650)),36);  
  carry_object("/d/obj/weapon/blade/blade.c")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/qujing/wudidong/obj/key-real");
  
}



void punish_player(object me)
{
    object *inv, ob;
    int i;
    inv=all_inventory(me);
    i=(int)sizeof(inv);
    while(i--)
    {
        ob=present(inv[i],me);
        destruct(ob);
        continue;
    }
    command("say "+me->name()+"你个混帐！叫你去好好看着那老秃驴，你竟敢把他给放跑了！");
    command("say 你好大的胆子！还敢回来跟老娘学本事！");
    command("say 不好好教训教训你，别人还都以为老娘是好欺负的了！");
    message_vision("只见玉鼠左手掐了个决，口中念念有词，对$N喝道：倒！\n", me);
    me->unconcious();
    message_vision("玉鼠精象提小鸡般提起$N，往后一扔。$N不见了！\n", me);
    me->move("/d/qujing/wudidong/punish");
    message("vision", "只听“咚”的一声，$N落了下来！\n", me);
    return;
}
/*********************************************************************/
string say_key()
{
  object me=this_player(), ob, npc=this_object();
  int mykar=me->query_kar();
  int real_key_condition;

  if(npc->is_fighting() || me->is_fighting())
    return ("没门！等着点！");

  message_vision(CYN"玉鼠对$N说：“好吧，拿去。”\n"NOR, me);
  if (npc->query_temp("gave_out_key"))
      real_key_condition=0;
  else real_key_condition=1;
  if (!real_key_condition)
    {
      ob=new("/d/qujing/wudidong/obj/key-fake");
    }
  else if (random(mykar)>8)
    {
      ob=new("/d/qujing/wudidong/obj/key-real");
      npc->set_temp("gave_out_key", 1);
    }
  else ob=new("/d/qujing/wudidong/obj/key-fake");
  ob->move(me);
  me->set_temp("mark/wudidong_yushu_gave_me_key", 1);
  return ("好好看守那秃驴！\n");
}
void killplayer(object me)
{
  this_object()->kill_ob(me);
}
/**************************************************************/
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}
void greeting(object me)
{
  int myspells=me->query_skill("spells");
  int mykar=me->query_kar();
  string npcname=this_object()->query("name");
  string npcrude=RANK_D->query_self_rude(this_object());
  string myrude=RANK_D->query_rude(me);

  if( !me || environment(me) != environment() ) return;
  if( me->query("family/family_name") == "陷空山无底洞")
    return;
  if( member_array("yu shu", me->parse_command_id_list())!=-1)
    {
      command("say 哪个混账？竟敢变成"+npcrude+"样子招摇撞骗？！找死！");
      kill_ob(me);
      return;
    }
  if( member_array("tian shu",me->parse_command_id_list())==-1 )
    {
      command("say 哪里来的"+myrude+"？无底洞不是你撒野的地方！拿命来！");
      command("hit " + me->query("id"));
      return;
    }
  if( random(mykar) > 8) return;
  else
    {
      message_vision(CYN ""+npcname+"对$N大喝道：呔！什么东西！？休想从"+RANK_D->query_self_rude(this_object())+"眼下溜过去！\n"NOR, me);
      message_vision(npcname+"大喊一声：现！$N顿时现出原形，原来是"+me->query("name")+"！\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}



