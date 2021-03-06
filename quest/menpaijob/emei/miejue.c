// miejue.c 灭绝师太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_job();
string ask_for_quit();
mixed out_master(mixed arg);
int ask_zhou();
int ask_guo();
int ask_dragon();
int ask_jiuyin();
#include "/quest/givegift.c"
#include "/quest/where.c"
     
 

string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("灭绝师太", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。\n");
        set("gender", "女性");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),                		
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
        set("inquiry",([
                "剃度"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "出家"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "还俗"  :  (: ask_for_quit :),
		"周芷若" : (: ask_zhou :),
		"郭靖" : (: ask_guo :),
		"黄蓉" : (: ask_guo :),
		"倚天屠龙" : (: ask_dragon :),
		"武林至尊" : (: ask_dragon :),
		"九阴速成篇" : (: ask_jiuyin :),
                "除妖" : (: ask_job :),
                "杀魔" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        set("str", 50);
        set("int", 55);
        set("con", 55);
        set("dex", 55);
        set("per", 20);

        set("max_qi", 28000);
        set("max_jing", 28000);
        set("neili", 38000);
        set("max_neili", 38000);
        set("jingli", 11500);
        set("max_jingli", 11500);

        set("combat_exp", 8500000);
        set("score", 1000);
        set_skill("persuading", 500);
        set_skill("throwing", 250);
        set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 280);
        set_skill("blade", 280);
        set_skill("literate", 260);
        set_skill("mahayana", 500);
        set_skill("buddhism", 500);
        set_skill("jinding-zhang", 380);
        set_skill("tiangang-zhi", 380);
        set_skill("huifeng-jian", 380);
        set_skill("yanxing-dao", 380);
        set_skill("zhutian-bu", 380);
        set_skill("linji-zhuang", 380);
        set_skill("bagua-dao", 380);
        set_skill("bagua-zhang", 380);
set_skill("unarmed", 280);
        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");


if (random(2)==0)
{
set("isyt",1);
	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yitian-jian");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fumo" :),
                (: perform_action, "sword.yitian" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
}
else
{
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");	
}
//        map_skill("magic","bashi-shentong");
        create_family("峨嵋派", 3, "掌门人");
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",900);
	set_temp("apply/damage",900);
        setup();

if (random(3)==0 && query("isyt")==1) carry_object("/clone/box/baowu/57")->wield();
else         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}


void attempt_apprentice(object ob)
{
   mapping ob_fam;
   mapping my_fam  = ob->query("family");

   string name, new_name;
   name = ob->query("name");

   if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
   {
      command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
      return;
   }
   switch (random(2))
   {
        case 1: break;
        default:
           if ((string)ob->query("class")!="bonze" )
           {
               command ("say 阿弥陀佛！贫尼不收俗家弟子。");
               return;
           }
           else
           {
               command ("say 阿弥陀佛！贫尼不收弟子。");
               return;
           }
   }
   if ((int)ob->query_skill("mahayana",1)<90||(int)ob->query_skill("linji-zhuang",1)<90)
   {
      command("say 你本门的功夫修为还太低。");
      return;
   }
   if ((int)ob->query("shen") < 50000)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   if ((string)ob->query("class")=="bonze" )
   {
        name = ob->query("name");
        new_name = "静" + name[2..3];
        ob->set("name", new_name);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第四代弟子!");
   }

   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派")) 
        return ("你和峨嵋没有渊源，贫尼不敢给你还俗。\n");
    if( (string)me->query("class")!="bonze" )
        return "阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say 阿弥陀佛！善哉！善哉！你一心要还俗，我也不挽留。\n");
        command ("say 我将废去你部分武功。请跪下(kneel)听宣。\n");
        return "如果不愿还俗的，就安心在此修炼吧。\n";
}

int do_kneel()
{
    object me,ob;
    mapping myfam;
    ob = this_object();
    me = this_player();
    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派")) 
{
        command ("say 你和峨嵋没有渊源，贫尼不敢给你还俗。\n");
return 1;
}
    if( (string)me->query("class")!="bonze" )
{
        command ("say 阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n");
return 1;
}
    if (!me->query_temp("pending/quit_bonze"))
{
        command ("say 阿弥陀佛，你想做什么啊？\n");
return 1;
}
command ("say 好，接下来，我将废去，你本门的武功。\n");
if (me->query_skill("linji-zhuang")>1)
{
me->delete_skill("linji-zhuang");
me->map_skill("force");
me->prepare_skill("force");
me->reset_action();
me->set("class","emei");
me->delete_temp("pending/quit_bonze");
}
message_vision(RED"\n$N在$n的身上点了几下,$n混身的力量，一下子全没了！。\n"NOR, ob, me);
command ("say 从现在开始，你就不是出家人了！。\n");
return 1;
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗贫尼？");
       return 0;
       }
   if(me->query_temp("emjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say 你任务怎么做的，杀了几个敌人？");
       return 0;
       }       
/*   if(obj->query("id") == "mingjiao ling" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say 干得好！\n");
       message_vision(HIY"$N将$n"HIY"叫起来。\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }*/
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 贫尼我要钱干什么?");
       return 0;
       }
//   if(obj->query("owner") != me->query("id")){
//       command("hehe "+(string)me->query("id"));
//       command("say 不错啊，但这活可不是你干的。");
//       /return 1;
//       }
//   else return 0;       
}
void destroying(object obj, object ob, object me)
{   
   object n_money;
   int exp,pot;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！贫尼就指点你两手功夫吧.\n"NOR,ob, me);
   exp=390+(me->query_temp("biaoshi")*(random(20)+50));
   exp=exp/2+188;
   addnl(me,"exp",exp);

  me->add("shen",100);
  me->add("score",10);

   tell_object(me, "你的侠义正气变强了，你了江湖阅历变强了。\n");
destruct(present("mingjiao ling",ob));

me->delete_temp("emjob2");
   me->delete_temp("xx_rob");
   ob->delete_temp("job_asked");
   me->delete_temp("robjob_exp");
   me->delete_temp("biaoshi");
   return;      
}
string ask_job()
{
  object me, ob,obn;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp = me->query("combat_exp"); 
 
    if( !wizardp(me) && me->query_temp("rob_start")) 
            return "不是叫你先去那里等我吗？怎么还在这里？";
    if( !wizardp(me) && me->query("family/family_name") != "峨嵋派")
            return "你是哪里来的奸细？";
      if(  !wizardp(me) && (int)me->query_skill("linji-zhuang",1) < 50)
            return "贫尼认为你的本门内功太差了。";

    if( !wizardp(me) && me->query_condition("emeijob"))
            return "贫尼现在还没有得到任何消息，你等会儿再来吧。";


    if(exp>=600000) j=5;
    else if(exp>=500000) j=4;
    else if(exp>=400000) j=3;
    else if(exp>=300000) j=2;   
    else j=3;   
  
    me->set_temp("rob_job", 1);
    me->delete_temp("biaoshi");
    message_vision(CYN"\n$N说到,有消息说魔教有一批弟子在密谋,对我派不利。\n"NOR, ob, me);
    ob->set_temp("job_asked", me->query("id"));
    ob->set_temp("dest", "emeijob");
    ob->set_temp("start_place", aquest["place"]);
    
    //message_vision(CYN"\n$N说到,"+aquest["place"]+"。"+aquest["short"]+"\n"NOR, ob, me);
    
    ob->set_temp("place", aquest["short"]);
    me->set_temp("j", j);    
    me->apply_condition("emeijob", 15);
    me->start_busy(1);
    obn = new(__DIR__"shangdui");
    obn->move(aquest["place"]);
    obn->set("arg", ob->query_temp("dest"));
    me->set_temp("rob_start", 1);
    return me->query("name")+"你就去"+ob->query_temp("place")+"消灭(xiaomie)魔教队伍。\n";    
}

void init()
{
   object ob, where, me;
   ::init();
   ob=this_object();
   where = environment(ob);
   if(ob->query_temp("dest")){
     if(interactive(me = this_player()) && me->query_temp("rob_job")
        && ob->query_temp("job_asked") == me->query("id")
        && file_name(where) == ob->query_temp("start_place")) {
           remove_call_out("waiting");
           call_out("do_back",120,me);
	    call_out("waiting", 1, ob, me);
           }
     else{
         remove_call_out("do_back");
         call_out("do_back", 90, ob);
         }
     }
  add_action("do_kneel", "kneel");
}
void waiting(object ob, object me)
{   
    if(!ob || !living(me)) return;
    command("nod "+me->query("id"));
    command("say 好，我们就在这里等着他们来吧。");
    ob->set_temp("wait_target", 1);
    me->set_temp("wait_target", 1);
    remove_call_out("wait_target");
    call_out("wait_target", 30, ob, me);
    return; 
}
void do_back(object me)
{
        me->delete_temp("wait_target");
        me->delete_temp("start_place");
        me->delete_temp("place");
        me->delete_temp("dest");
        message_vision("$N转过山丘，几个起落就不见了。\n", me);
        me->move("/d/emei/hcahoudian");  
        message_vision("$N急急忙忙地走了过来。\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);             
}
void del_temp(object me) {me->delete_temp("job_asked");}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N说道：耶？人怎么不见了？\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("miejue shitai", environment(me)))){ 
       tell_object(me,"你发现灭绝师太不见了，只好转身离开。\n");
       tell_room(environment(me), me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
       me->delete_temp("rob_job");
//       me->clear_condition("rob_task");
       me->delete_temp("wait_target");
       return 1;
       }

    obj = new(__DIR__"shangdui");
    obj->move(environment(me)); 
    obj->set("arg", ob->query_temp("dest"));
    message_vision(HIY"\n只听一阵脚步声传来，一队明教的人马出现在眼前！\n\n"NOR, ob);
    tell_object(me,"敌人终于出现了！\n"); 
    message_vision(HIY"$N对着$n大声命令道：你快消灭(xiaomie)魔教队伍，我来对付其他人！\n"NOR, ob, me); 
    message_vision("说完$N就冲上前去，和几个明教高手打斗追逐开了。\n", ob);   
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("wait_target");
    me->set_temp("rob_start", 1);
}
int ask_guo()
{
    object me=this_player();
    if( me->query("shen") < -10000 ) {
        command("say 看你一身邪气，还敢打听郭大侠的名号？\n");
        command("consider "+ me->query("id"));
        return 1;
    }

    command("say 本派的创派祖师郭女侠，乃是当年大侠郭靖的小女儿。郭大侠当年名震天下，生平有两
项绝艺，其一是行军打仗的兵法，其二便是武功。郭大侠的夫人黄蓉黄女侠最是聪明机智
，她眼见元兵势大，襄阳终不可守，他夫妇二人决意以死报国，那是知其不可而为之的赤
心精忠，但郭大侠的绝艺如果就此失传，岂不可惜？何况她料想蒙古人纵然一时占得了中
国，我汉人终究不甘为鞑子奴隶。日后中原血战，那兵法和武功两项，将有极大的用处。
因此她聘得高手匠人，将杨过杨大侠赠送本派郭祖师的一柄玄铁重剑熔了，再加以西方精
金，铸成了一柄屠龙刀，一柄倚天剑。");
	me->set_temp("jiuyin/emei", 1);
        return 1;
}

int ask_zhou()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 1 ) {
        command("say 周芷若是我派的第四代弟子，此刻虽然不及众位师姊，日后却是不可限量。");
        me->set_temp("jiuyin/emei", 2 );
        return 1;
    }
    command("say 你问她做什么？\n");
    command("say " + me->query("name") + "定然是看上了她，要她堕入你的彀中。");
    command("consider " + me->query("id") );
    return 1;
}

int ask_dragon()
{
    object me=this_player();
    object ob = this_object();
    if( me->query_temp("jiuyin/emei") < 4 ) {
        command("say 我派的重大秘密你怎么知道了？拿命来！");
        ob->set("neili", 10000);
        ob->kill_ob(me);
        return 1;
    }
    command("say 既然周芷若难成大器，那你就给我起个誓吧。");
    me->set_temp("jiuyin/emei", 5 );
    return 1;
}

int ask_jiuyin()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("jiuyin/emei")) {
if(environment(ob)->query("short")!="华藏庵后殿")
{
tell_object(me,"这是什么地方？？这地方不能给你\n");
 return 1;
}
if(environment(ob)->query("already"))
{
tell_object(me,"你来晚了，别人已经把九阴速成篇拿走了!\n");
return 1;
}



		if (present("jiuyin sucheng", me)) {
			command("say 我不是已经给你了么？");
			return 1;
		}
		if( me->query_skill("xianglong-zhang", 1) > 0)
        		command("say 降龙十八掌你已经学了，这卷九阴速成篇你就拿去学吧。");
		else
        		command("say 你的武学路子与降龙十八掌的刚阳劲力不符，这本九阴速成篇你就拿去学吧。");
        	
                environment(ob)->set("already",1);

		new("/clone/book/jiuyin-sucheng")->move(me);
		message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到九阴速成篇啦。\n"NOR, users());
		return 1;
	}
	return 0;
}
