// /kungfu/class/xueshan/xuedao.c  Ѫ������
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_girl();

int ask_job();
int ask_jobover();
int ask_fail();
string ask_for_quit();
#include "/quest/givegift.c"
void create()
{
        set_name("Ѫ������", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
���������Ż��ۣ���ͼ��ϣ���ͷ���������϶������ơ�������Ѫ���ŵ��Ĵ����š�
LONG
        );
        set("title",HIR"Ѫ���ŵ��Ĵ�����"NOR);
        set("gender", "����");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("max_qi", 86000);
        set("max_jing", 86000);
        set("neili", 86000);
        set("max_neili", 86000);
        set("jiali", 50);
        set("combat_exp", 9900000);
        set("score", 180000);

        set_skill("lamaism", 580);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 380);
        set_skill("sword", 120);
        set_skill("dodge", 280);
        set_skill("longxiang", 380);
        set_skill("shenkong-xing", 280);
        set_skill("hand", 280);
        set_skill("cuff", 280);
        set_skill("yujiamu-quan", 380);
        set_skill("dashou-yin", 380);
        set_skill("mingwang-jian", 320);
        set_skill("xue-dao", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");


if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}
	set("inquiry", ([
                "��Ů" : (: ask_job() :),
                "job" : (: ask_job() :),
                "���" : (: ask_jobover() :),
                "over" : (: ask_jobover() :),
                "ʧ��" : (: ask_fail() :),
                "����"  :  (: ask_for_quit :),
		"ˮ��": (: ask_girl :),
	]) );
        set("chat_chance", 2);
	set("chat_msg", ({
"Ѫ������̧��ͷ��������˼�����������������Բ�ˣ�����ɽɱ���˼������ˡ���\n",
"Ѫ������޺޵�˵����ʲôʱ��������ԭ�����ָ��췭�ظ�����\n",
"Ѫ������ҧ���гݣ���¶�׹��˵�����´�����ն�ݳ�����һ�����Ҳ��������\n",
"Ѫ���������������������ʹ��ˣ�������һ��Ҳ����������������Ϊ���⡣\n",
}) );

        create_family("ѩɽ��", 2, "����");
        set("class", "bonze");

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2250);


        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();

        add_money("gold",2);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����")
        {
                command("say �Ҳ���Ůͽ�ܡ�\n");
                return;
        }
        if ((string)ob->query("family/family_name") != "ѩɽ��")
        {
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��ŵ��ӣ�������ذɣ�\n");
                return;
        }
        if ((int)ob->query("shen") > -100000)
        {
                command("say ���ǲ����������������ɱ�˶����ᣡ\n");
                return;
        }
        if ((int)ob->query_skill("longxiang", 1) < 60)
        {
                command("say ����Ѫ���ţ���ϰ���󹦷�����Ҫ�ġ�\n");
                return;
        }
        command("haha");
        command("nod");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "Ѫ���ŵ��������" NOR);
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
      if( !wizardp(me) && (int)me->query_skill("longxiang",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }

        if( !wizardp(me) && me->query("family/family_name") != "ѩɽ��")
           {
                      message_vision("$N����$n˵���������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (!wizardp(me) && me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "����Ů����û��ô���ף��㻹�����߾���������");
                return 1;
}
    if (!wizardp(me) && (int)me->query_condition("guojob2_busy"))
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (!wizardp(me) && (int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if (!wizardp(me) && me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ���Ǳ��̫����.�Ҳ���ʲô�û�!!");
                return 1;
        }
        if (!wizardp(me) && me->query("quest") ) 
      	{
command("say "+me->query("name")+"���ϻ��б��������ȥ����������ɣ�");
return 1;
}
        if (me->query("kill_xueshan") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "����־ͬ���ϣ��ٺٺ١�");
                command("say " + me->query("id") + " ��˵�ڡ�" + quest["short"]             + "�������и�������Ů����ȥ�ɣ�\n" NOR);
                me->set("kill_xueshan", 1);
                me->set("quest/quest_type", "��");
                me->set("quest/quest", "������Ů");
                me->set("task_time", time() + 310);
                me->apply_condition("menpai_busy",8);
                ob = new(__DIR__"meinv",1);
                ob->move(quest["place"]);
                me->start_busy(3);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set("id", me->query("id")+ob->query("id"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_xueshan") == 1) {
                command("pk");
                command("say �㺦����û����Ů��,������������.");
                me->apply_condition("menpai_busy",8);
me->delete("kill_xueshan");
                return 1;
                }
}



int accept_object(object me, object obj)
{
   int i;
   object fang;
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(obj->query("id") == "mei nu" && me->query("kill_xueshan") == 1 && me->query_temp("xsjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say ��������ô���ģ�ɱ�˼������ˣ�");
       return 0;
       }
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
  
   
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
       
       if(((int)me->query("jinyong/book3")==3) && (string)obj->query("id") == "shui sheng")
{
        message("vision", me->name() + "��Ѫ������һλˮ�ϡ�\n", environment(me), ({me}));
	command("pat " + me->query("id"));  
	command("say ��Ȼ����Ҳ�����Ϊ�˰���������죬ֻ�а������˳���! ");  
	this_object()->kill_ob(me); 
	fang = load_object("/d/xuedao/npc/huatiegan");
	fang->move(environment(me));
	fang->kill_ob(me); 
	me->set_temp("killxdao",1);
	message("vision", fang->name() + "��������˽�����ɱ�����㡣\n", environment(me), ({me}));
 call_out("destroying2", 0, obj);                       
return 1;
}       

if (me->is_fighting())
		return 0;

if (me->is_busy())
		return 0;



	if (!me->query("szj/passed")
	 || me->query("szj/over200")
	 || !me->query_temp("szj/shui")
	 || (string)obj->query("id") != "shui sheng"
	 || me->query_temp("killxdao"))

		return 0;

	me->delete_temp("szj");
        message("vision", me->name() + "��Ѫ������һλˮ�ϡ�\n", environment(me), ({me}));
	command("pat " + me->query("id"));
        call_out("starting", 1, me, this_object(), obj);
        return 1;

//   if(me->query("kill_xueshan") == 0 ){
//       command("hehe "+(string)me->query("id"));
//       command("say �������������û����ɰ���");
//       return 1;
//       }
//   else return 0;       
}



int ask_jobover()
{
   int i;
   object fang;
      object n_money;
   int kar, exp, pot;
   object ob=this_object();
   object me=this_player();
   if(!me || environment(me) != environment()) return 0;

   if (me->query("kill_xueshan") == 1 && me->query_temp("xsjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say ��������ô���ģ�ɱ�˼������ˣ�");
       return 0;
       }
  
     if(me->query_temp("must_killby") != me->query("id"))
   {
          command("consider "+(string)me->query("id"));
       command("say ����£�����û�й�ϵ��!");
       return 0;	
}
  
   if(me->query_temp("must_killby") == me->query("id"))
   {
       command("nod "+(string)me->query("id"));
       command("say �ٺ�.�ɵúã�\n");
   kar = random(me->query("kar")) * 10;
if (kar >500) kar=500;
   exp = 650 + kar;
   pot = 500 + random(kar);


//   if(obj) destruct(obj);
//   if(ob) destruct(ob);
  // if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return 0;
      }
   command("pat "+me->query("id"));
   message_vision(HIR"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������������������湦��.\n"NOR,ob, me);
exp=exp/2+88;
addnl(me,"exp",exp);
                me->add("score",50);
                me->add("shen",-300);
                me->delete("quest");
                destruct(present("mei nu",ob));
                me->apply_condition("guojob2_busy",12);
                me->apply_condition("huang_busy",12);
 me->delete_temp("xsjob2");
                me->delete("kill_xueshan");
                me->set_temp("must_killby",0);
                me->delete_temp("must_killby");
   message_vision(HIM"$N˵��Ͱ���Ů�ؽ��˺����ɽ��......\n"NOR,ob);
                     
       return 1;
       }

 
}








string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "ѩɽ��")) 
        return ("���ѩɽ��û��ԨԴ���Ҳ��Ҹ��㻹�ס�\n");
    if (me->query("combat_exp")< 1000000)
        return ("�����㱾�£��ҿɲ��Ҹ��㻹�ס�\n");

    if ((int)me->query_skill("lamaism", 1) < 180) 
                command("say ����ϰ�������ķ�����,�ҿɲ��Ҹ��㻹�ס�");

    if ((int)me->query_skill("longxiang", 1) < 180) 
                command("say ����ϰ���������������,�ҿɲ��Ҹ��㻹�ס�");

    if (me->query("combat_exp")< 1000000)
        return ("�����㱾�£��ҿɲ��Ҹ��㻹�ס�\n");

    if( (string)me->query("class")!="bonze" )
        return "���Ѿ����׼����ˡ�\n";

        command ("say ��һ��Ҫ���ף�����������ͬ�����ˡ�\n");
        command ("haha");
        command ("say �Ժ������о�ͬ�ԣ���Ů��һ�𡣡���������\n");
        me->set("class", "xueshan");
}
int ask_girl()
{
		int i;
	object fang;
	object who,where;
	who=this_player();
	where = environment(who);
	
	if (this_player()->query("shen") > 0) {
		command("say �����ϲ����������ʿ�ύ�����߰ɣ�");
		return 1;
	}
	
	
if(((int)this_player()->query("jinyong/book3")==2))
{

		  	if((!(int)who->query_temp("killsx2")))
	{
		message_vision("$N��$n˵���� ���Ȱ������˻����ɰɡ�\n",this_object(),who);
		return 1;	
	}

		  	if((!(int)who->query_temp("killsx3")))
	{
		message_vision("$N��$n˵���� ���Ȱ����������з�ɡ�\n",this_object(),who);
		return 1;	
	}

		  	if((!(int)who->query_temp("killsx1")))
	{
		message_vision("$N��$n˵���� ���Ȱ�������½����ɡ�\n",this_object(),who);
		return 1;	
	}

		  	if((!(int)who->query_temp("killsx4")))
	{
		message_vision("$N��$n˵���� ���Ȱ�������ˮᷰɡ�\n",this_object(),who);
		return 1;	
	}		


command("thank " + who->query("id"));
	message_vision("$N��$n˵���� $n�ɵĲ���\n",this_object(),who);
	message_vision("$N��$n˵���� ���������������$n��\n",this_object(),who);
	
	i = 500+random(800);
	who->set("jinyong/book3",3);
	who->add("combat_exp",i+10880);
	who->add("potential",i*13);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+10880)+"�㾭��"+
	           chinese_number(i*13)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
return 1;
}	
	command("say ��˵ˮ᷵�Ů��ˮ�ϳ���ͦ���µģ��ҵ�ͦ���ʶ��ʶ��");
	command("say ����ú���ͻ�������һ����ȥ�������Ҵ�������ô����");
	command("say �㾡�ܷ��ģ����ǲ����˺����ġ�");
	this_player()->set_temp("szj/shui", 1);
	return 1;
}


void starting(object me, object ob, object obj)
{
	obj->revive(1);
	obj->reicarnate();
	obj->set("neili", obj->query("max_neili"));
	obj->set("eff_qi", obj->query("max_qi"));
	obj->set("qi", obj->query("max_qi"));
	obj->set("eff_jing", obj->query("max_jing"));
	obj->set("jing", obj->query("max_jing"));
	message_vision(HIW"$n���Ӷ��˶������������˼��������ѹ�����\n"NOR, me, obj);
	command("grin " + obj->query("id"));
	message_vision(HIC"$n���´�����ˮ�ϣ�˫�۽���������ҡ�\n"NOR, me, ob);
	message_vision(HIC"$nͻȻɫ�Դ󷢣�һ��§סˮ�ϣ�����ȥ����������\n\n"NOR, me, ob);
	me->start_busy(100);
	call_out("story1", 3, me, ob, obj);
}

void story1(object me, object ob, object obj)
{
	object room, shui, lu, liu, hua;
	room = load_object("/d/xuedao/nroad3");
	if (!objectp(shui=present("shui dai", room)) || !objectp(lu=present("Lu tianshu", room))) {
		call_out("finish", 1, me, ob, obj);
		return;
	}
	room = load_object("/d/xuedao/sroad3");
	if (!objectp(liu=present("liu chengfeng", room))) {
		call_out("finish", 1, me, ob, obj);
		return;
	}
	room = load_object("/d/xuedao/nroad6");
	if (!objectp(hua=present("Hua tiegan", room))) {
		call_out("finish", 1, me, ob, obj);
		return;
	}
	message_vision(HIW"���˳����е�����Ѫ��ɮ���������Ů�����������°��ݣ���������ӵ���ߣ���Ҳ׷�㵽��ߡ���\n"NOR, me);
	message_vision(HIW"�������ĸ��˵����������е������仨��ˮ�⡪��ˮ�����䣡�仨��ˮ�⡪��ˮ�����䣡��\n"NOR, me);
	message_vision(HIC"����ɤ�����Բ�ͬ������ϣ�����׳�����Ƴ�����߿���������֮�񣬸���ʤ������\n"NOR, me);
	command("say ���ĸ��һ��Ȼ�����ˣ������ű����������˹����ǿ��\n");
	call_out("story2", 2, me, ob, obj, shui, lu, liu, hua);
}

void story2(object me, object ob, object obj, object shui, object lu, object liu, object hua)
{
	shui->move("/d/xuedao/shandong3");
	lu->move("/d/xuedao/shandong3");
	liu->move("/d/xuedao/shandong3");
	hua->move("/d/xuedao/shandong3");
	shui->set("eff_qi",2000);
	shui->set("qi",2000);
	shui->set("neili",1000);

	lu->set("eff_qi",2000);
	lu->set("qi",2000);
	lu->set("neili",1000);

	liu->set("eff_qi",2000);
	liu->set("qi",2000);
	liu->set("neili",1000);
	
	hua->set("eff_qi",2000);
	hua->set("qi",2000);
	hua->set("neili",1000);	
	hua->kill_ob(ob);
	lu->kill_ob(ob);
	liu->kill_ob(ob);
	shui->kill_ob(ob);
	ob->kill_ob(shui);
	ob->kill_ob(lu);
	ob->kill_ob(liu);
	ob->kill_ob(hua);
	call_out("checking", 2, me, ob, obj);
}

void checking(object me, object ob, object obj)
{
	if (!ob) {
		me->start_busy(1);
		return;
	}
	if (present("shui dai", environment(me))
	 || present("Lu tianshu", environment(me))
	 || present("liu chengfeng", environment(me))
	 || present("Hua tiegan", environment(me))) {
		call_out("checking", 1, me, ob, obj);
		return;
	}
	message_vision(HIY"$nս���Ĵ���֣�Ԫ����Ȼ���ˣ�����ˮ�ϻ���Լ�������
������һ�ᣬ˳�ֻӵ�����ˮ�Ͼ��п��¡�\n"NOR, me, ob);
	me->set_temp("szj/wait_baohu", 1);
	me->start_busy(1);
}

void finish(object me, object ob, object obj)
{
	message_vision(HIY"$n��ȣ��Ҿ�������Ҳ��������óѵģ�˵�꣬һͷײ��ʯ�ڡ�\n"NOR, me, obj);
	obj->die();
	me->start_busy(1);
}
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
                if (!who)        	return ;
  	if(((int)who->query("jinyong/book3")>=4))
	{
//::die();	
	}
        else if(who && who->query_temp("killxdao")) {
        	message_vision("$N˵�����ⲻ���ܣ��ҵĵ���������˫��\n" NOR,this_object());
        	message_vision("$N˵����������� ������......\n" NOR,this_object());
		i = 100+random(2000);
		who->set("jinyong/book3",4);
		who->add("combat_exp",i+15000);
		who->add("potential",i*15);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+15000)+"�㾭��"+
		           chinese_number(i*15)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		who->save();
        }
	::die();
}
