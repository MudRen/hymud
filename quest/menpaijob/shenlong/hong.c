// hong.c �鰲ͨ

#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
string ask_du1();
int ask_me();
int ask_du();
int ask_job();
int ask_fail();
int i;
#include "/quest/givegift.c"
void create()
{
	set_name("�鰲ͨ", ({ "hong antong", "hong" }));
	set("title",  HIY"������"NOR"����" );
	set("nickname", HIR "�����ɸ�" NOR);
	set("long", "�������书����������˵�̸֮ɫ��������̽����鰲ͨ��\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 65);
	set("int", 60);
	set("con", 60);
	set("dex", 68);
	
	set("max_qi", 28000);
	set("eff_qi", 28000);
	set("max_jing", 23000);
	set("eff_jing", 23000);
	set("neili", 28000);
	set("max_neili", 28000);
	set("jiali", 100);
	set("combat_exp", 9500000);
	set("score", 400000);

        set_skill("force", 250);
	set_skill("shenlong-xinfa", 380);
        set_skill("dodge", 200);
	set_skill("yixingbu", 380);
        set_skill("hand", 250);
	set_skill("shenlong-bashi", 380);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 380);
        set_skill("parry", 250);
set_skill("claw", 300);
set_skill("strike", 300);
set_skill("cuff", 320);
        set_skill("staff", 200);
        set_skill("sword", 300);
        set_skill("zhaosheshu", 580);
        set_skill("yangsheshu", 580);
	set_skill("shedao-qigong", 380);
	set_skill("literate", 200);
	set_skill("dulong-shenzhua", 380);
	set_skill("xuanming-zhang", 380);
  set_skill("qingshe-sword", 380);
	set_skill("diwangquan", 380);
        
        set_skill("leg",200);
        set_skill("shenlong-tuifa",380);
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shedao-bashi");
        map_skill("staff", "shedao-qigong");

	map_skill("strike", "xuanming-zhang");
	map_skill("claw", "dulong-shenzhua");
	map_skill("cuff", "diwangquan");
	prepare_skill("strike", "xuanming-zhang");
	prepare_skill("cuff", "diwangquan");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
		(: command("zhaoshe") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.wanshe" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "strike.lang" :),
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),                	                	
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shewu" :),
                (: perform_action, "hand.flower" :),
                (: perform_action, "hand.meinu" :),                
                (: perform_action, "hand.yingxiong" :),             
                (: perform_action, "cuff.sanzhao" :),                
                (: perform_action, "cuff.sheshen" :),                
                (: perform_action, "cuff.superbashi" :),                                
                (: perform_action, "cuff.sxbb" :),                                	                	
                      }) );
if (random(2)==0)
{
i=1;
        map_skill("sword", "qingshe-sword");
        map_skill("parry", "qingshe-sword");        
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
		(: command("zhaoshe") :),
                (: perform_action, "sword.jiang" :),
                (: perform_action, "sword.psxf" :),
                (: perform_action, "sword.qscd" :),
                (: perform_action, "sword.slj" :),
                (: perform_action, "strike.lang" :),
                (: perform_action, "strike.ying" :),
                (: perform_action, "strike.zhe" :),        
                (: perform_action, "staff.shewu" :),        	                	
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shewu" :),
                (: perform_action, "hand.flower" :),
                (: perform_action, "hand.meinu" :),                
                (: perform_action, "hand.yingxiong" :),                
                (: perform_action, "cuff.sanzhao" :),                
                (: perform_action, "cuff.sheshen" :),                
                (: perform_action, "cuff.superbashi" :),                                
                (: perform_action, "cuff.sxbb" :),                                	                	
                      }) );
}
	create_family("������",1,"����");

        set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao)��\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao)��\n",
		"�鰲ͨ" :  "\n�㲻������ǲ���?\n",
		"����" :  "\n�Ҿ��������̽�����\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
                "��ı" : (: ask_me() :),
                "�ƶ�" : (: ask_du() :),
                "jiedu" : (: ask_du() :),
                "����" : (: ask_job() :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
		"����" : (: ask_du1 :),
		"diaogan" : (: ask_du1 :),
       ]) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);

	setup();
if (i==1)
{
        carry_object("/clone/box/baowu/48")->wield();
}
else
{
        carry_object("/d/baituo/obj/shenshezhang")->wield();
}
//	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say ��Խ����Խ��׵������Ե׵ġ�");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(me);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me); 
                return 0;
        } else {
                command("say �Һ鰲ͨ�������������ʥ����ô������");
                message_vision("�鰲ͨ΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
	return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵��ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "���겻��") >=0 && (strsrch(arg, "�����ɸ�") >=0
         || strsrch(arg, "��������") >=0 || strsrch(arg, "������ʥ") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲����ҷ�����������������㣿!");
			this_object()->set_leader(this_player());
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player()); 
        }
        return 1;
}

// ���겻��,�����ɸ�,��������,������ʥ

void die()
{
			int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
message_vision("\n$N���������,��Ȼ������ɱ����,....��˵���������۵������ˡ�\n", this_object());

if((int)who->query("jinyong/book7")==4 && who->query_temp("book754"))
{	
	i = 500+random(800);
	who->set("jinyong/book7",5);
	who->add("combat_exp",i+12880);
	who->add("potential",i*15);
	who->add("mpgx",10);
	who->add("expmax",2);
message_vision("\n$N˵�������һ���ϵ�����صĻ��ȥץ�г����Ϻ��У�������ҲҪ����ˣ����й������ë�ӣ��Ҳ���ܵ�....��\n", this_object());
	tell_object (who,"��Ӯ����"+chinese_number(i+12880)+"�㾭��"+
	           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}

	::die();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
	add_action("do_flatter", "flatter");
}

void greeting(object ob)
{
	object obj;
	return;
}

void attempt_apprentice(object ob)
{
    if (ob->query("party/party_name") != HIY "������" NOR ) {
        command("say �㲻�Ǳ��̽���, ����������!");
	return;
    }
    if ((int)ob->query_skill("shenlong-xinfa",1) < 60 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
	return;
    }
    if ((int)ob->query_skill("shedao-qigong",1) < 60 ) {
        command("say ����ߵ��湦̫����,����ŬŬ�������һ�°�!");
	return;
    }
    if ((int)ob->query("shen") > -10000  ) {
        command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
	return;
    }
    command("say �ܺã��ܺá�");
    command("recruit " + ob->query("id"));
}
 
int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = ("/quest/where")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;
        if (me->query("quest") ) 
      	{
command("say "+me->query("name")+"���ϻ��б��������ȥ����������ɣ�");
return 1;
}

        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "��42�¾��Ǻ��ѵģ��㻹�����߾���������");
                return 1;
}
      if( (int)me->query_skill("shenlong-xinfa",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }
    if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥ��42�¾���");
                return 1;
        }


        if (me->query("kill_shenlong") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ�ҽ̳���������̫���ˡ�");
                command("say " + me->query("id") + " 42�¾��ڡ�" + quest["short"]             + "�����֣���ȥ�ɣ�\n" NOR);
                me->set("kill_shenlong", 1);
                me->set("quest/quest_type", "Ѱ");
                me->set("quest/quest", "42�¾�");
                me->set("task_time", time() + 310);
me->apply_condition("menpai_busy",8);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                 me->start_busy(3);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("neili", me->query("max_neili"));
                ob->set("max_neili", me->query("max_neili"));
                ob->set("qi", me->query("max_qi")/2);
                ob->set("eff_qi", me->query("max_qi")/2);
                ob->set("max_qi", me->query("max_qi")/2);
                ob->set("jing", me->query("max_jing"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_du()
{

        object me = this_player();
        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n���һ�������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }




me->clear_condition("sl_poison");
me->clear_condition("shenlong_poison");
me->clear_condition("cold_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("xuanming_poison");
me->clear_condition("snake_poison");

if (me->query_condition("ill_fashao"))
        me->clear_condition("ill_fashao");

if (me->query_condition("ill_kesou"))
        me->clear_condition("ill_kesou");

if (me->query_condition("ill_shanghan"))
        me->clear_condition("ill_shanghan");

if (me->query_condition("ill_zhongshu"))
        me->clear_condition("ill_zhongshu");

if (me->query_condition("ill_dongshang"))
        me->clear_condition("ill_dongshang");
        

if (me->query_condition("chanchu_poison"))
{
me->clear_condition("chanchu_poison");
command("say �����ܶ��Ұ���ұ����.");
}        
else if (me->query_condition("wugong_poison"))
{
me->clear_condition("wugong_poison");
command("say �����򼶾�Ұ���ұ����.");
}        
else if (me->query_condition("snake_poison"))
{
me->clear_condition("snake_poison");
command("say ����߶��Ұ���ұ����.");
}
else if (me->query_condition("ice_poison"))
{
me->clear_condition("ice_poison");
command("say ��ĺ����������Ұ���ұ����.");
}
else if (me->query_condition("juehu_hurt"))
{
me->clear_condition("juehu_hurt");
command("say ��ľ��������Ұ���ұ����.");
}
//else     command("say ������û������ұ�Ķ�.");
            command("say ���ˣ���������.");
                return 1;
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_shenlong") == 1) {
                command("sigh");
                command("say ��������Ҳ����42�¾�!");
                me->delete("kill_shenlong");
                me->apply_condition("menpai_busy",6);
                return 1;
                }
}


int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
              if(ob->is_busy())
{
       //command("pat " + me->query("id"));
       command("say ������æ��");
       return 0;
       }       
   if(obj->query("id") == "42jing shu" && me->query("kill_shenlong") == 1
   && obj->query("byname") ==me->query("name") && !ob->is_busy())
   {
   	   	ob->start_busy(2);
       command("nod "+(string)me->query("id"));
       command("say �ɵúã�\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
//   if(me->query("kill_shenlong") == 0 ){
//       command("hehe "+(string)me->query("id"));
//       command("say �������������û����ɰ���");
//       return 1;
//       }
//   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 10;
if (kar >500) kar=500;
if (kar <150) kar=150;
   exp = 550 + kar;
   pot = 480 + random(kar);

   if(obj) destruct(obj);
/*
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ����һ�42�¾�����������\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
 destruct(present("42jing shu",ob));
exp=exp/2+88;
addnl(me,"exp",exp);

                me->add("score",50);
                me->delete("quest");
                me->delete("kill_shenlong");
*/
   return;      
}
string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (this_player()->query_temp("sld"))
		return "�Ҹո��������ֶ����ˡ�";

	ob = new(__DIR__"obj/diaogan");
	ob->move(this_player());
	this_player()->set_temp("sld",1);
	return "�ðɣ������������ѵ��˰ɡ�";
}



int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book7")!=4))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
				return 1;	
	}
	
	
	  	if(!(int)who->query_temp("book751"))
	{
		message_vision("$N��$n˵���� ��������ͷ��ȥ˵ȥ�ɣ�\n",this_object(),who);
				return 1;	
	}

	  	if(!(int)who->query_temp("book752"))
	{
		message_vision("$N��$n˵���� ��������ͷ��ȥ˵ȥ�ɣ�\n",this_object(),who);
				return 1;	
	}
	
	  	if(!(int)who->query_temp("book753"))
	{
		message_vision("$N��$n˵���� �����ҷ���ȥ˵ȥ�ɣ�\n",this_object(),who);
				return 1;	
	}
	
	command("kick " + who->query("id"));
	
	message_vision("$N��$n˵���� �ҽ̵��¼�Ȼ��֪�������ȥ���� ��\n",this_object(),who);
        kill_ob(who);	            
        who->set_temp("book754",1);
        who->kill_ob(this_object());
	return 1;
}