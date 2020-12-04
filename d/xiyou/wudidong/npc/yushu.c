
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// yushu.c, ����
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
  set_name("����", ({"yu shu","yushu", "shu", "monster"}));
    set_weight(1000000);
  set("gender", "Ů��" );
  set("age", 23);
  set("long", 
"���������޵׶��Ķ����ˡ������޵�����������������������\n"
"Ҳ��֪Ϊʲô��ʻ�δ���ɱ���Χ�ˡ���˵�����칬���ף�Ҳ\n"
"��֪��١�\n");
  set("title", "��ӿ����");
  set("combat_exp", 61500000);
  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 1, "����");
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
"����" : (: ask_mieyao :),
       "key": (: say_key :),
       "Կ��": (: say_key :),
       "name": "����������޵׶��Ŀ�ɽ��ʦ��",
       "here": "��������ݿ�ɽ�޵׶����������ʮ�������Ҳ�κ��Ҳ��ã�",
       "rumors": "����ո�ץסһ�����С��������Ͼ�������������ˡ�",
       "�������": "���ʣ����˲���ȥ�ҳ��ӣ�",
       "����": "�ٺ٣��������������ء��������Ӹɾ��˾Ϳ��������˳��ˡ�\n"
          "����Ҳ������ȥ�������ˡ�˵�������Ѿ������ˡ�",
       "����": "Ҫ����Ҳ�У����ǲ�֪���Ұ�Կ�׷��Ķ��ˡ�",
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
    command("say "+me->name()+"������ʣ�����ȥ�úÿ�������ͺ¿���㾹�Ұ����������ˣ�");
    command("say ��ô�ĵ��ӣ����һ���������ѧ���£�");
    command("say ���úý�ѵ��ѵ�㣬���˻�����Ϊ�����Ǻ��۸����ˣ�");
    message_vision("ֻ�������������˸��������������дʣ���$N�ȵ�������\n", me);
    me->unconcious();
    message_vision("��������С��������$N������һ�ӡ�$N�����ˣ�\n", me);
    me->move("/d/xiyou/wudidong/punish");
    message("vision", "ֻ�����ˡ���һ����$N����������\n", me);
    return;
}
/*********************************************************************/
string say_key()
{
  object me=this_player(), ob, npc=this_object();
  int mykar=me->query_kar();
  int real_key_condition;

  if(npc->is_fighting() || me->is_fighting())
    return ("û�ţ����ŵ㣡");

  message_vision(CYN"�����$N˵�����ðɣ���ȥ����\n"NOR, me);
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
  return ("�úÿ�����ͺ¿��\n");
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
  if( me->query("family/family_name") == "�ݿ�ɽ�޵׶�")
    return;
  if( member_array("yu shu", me->parse_command_id_list())!=-1)
    {
      command("say �ĸ����ˣ����ұ��"+npcrude+"������ҡײƭ����������");
      kill_ob(me);
      return;
    }
  if( member_array("tian shu",me->parse_command_id_list())==-1 )
    {
      command("say ��������"+myrude+"���޵׶���������Ұ�ĵط�����������");
      command("hit " + me->query("id"));
      return;
    }
  if( random(mykar) > 8) return;
  else
    {
      message_vision(CYN ""+npcname+"��$N��ȵ���߾��ʲô�������������"+RANK_D->query_self_rude(this_object())+"�������ȥ��\n"NOR, me);
      message_vision(npcname+"��һ�����֣�$N��ʱ�ֳ�ԭ�Σ�ԭ����"+me->query("name")+"��\n", me);
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



