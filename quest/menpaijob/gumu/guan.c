//snowman 28/02/98
#include <ansi.h>
inherit NPC;
#include "/quest/givegift.c"
int j=3;
int ask_rob();
void create()
{
        set_name(HIR"�ɹ�Ԫ˧"NOR, ({ "yuanshuai"}));
       set("long",
                "һ���ɹ�Ԫ˧��\n");
        set("attitude", "friendly");
        set("gender", "����");
        set("age", 38);
        set("per", 40);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);
	 set_temp("no_kill",1);
        set("qi", 3500);
        set("no_kill", 1);
        set("max_qi", 3500);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("env/wimpy", 40);
        set("chat_chance", 99);
	set("chat_msg_combat", ({
		(: command("get all") :),
		(: command("get skeleton") :),
                      }) );
        setup();
        carry_object("d/gumu/npc/obj/baipao")->wear();
}

void init()
{
  add_action("do_rob", "shayuanshuai");
  add_action("do_quit","exert");
  add_action("do_guard", "halt");
        remove_call_out("leave");
        call_out("leave",600);
//        call_out("leave",10);
}

int do_rob(string arg)
{
   object me, ob;   
   //string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
   	
   	if (!arg )
   	return notify_fail("��Ҫ��ʲô�������� shayuanshuai ���id��\n");
   	
   	if (arg!=me->query("id"))
   	return notify_fail("��Ҫ��ʲô���� ������ shayuanshuai ���id��\n");
   	
   	if(me->query("id") !=ob->query_temp("jobname"))
		return notify_fail("���Ǳ��˵�����\n");
   
   
	if(environment(me)->query("no_fight"))
		return notify_fail("���ﲻ��򶷣�\n");
   if(!living(ob))
   return notify_fail("û������ɱ˭��!!\n"); 
   if(objectp(present("fawang", environment(me))))
   return notify_fail("�⼸���ɹŻ��̷��������书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  
   if(objectp(present("weishi", environment(me))))
   return notify_fail("�⼸���ɹű������书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  
   
   
    if(objectp(present(me->quuery("id")+"fawang", environment(me))))
   return notify_fail("�⼸���ɹŻ��̷��������书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  
   if(objectp(present(me->quuery("id")+"weishi", environment(me))))
   return notify_fail("�⼸���ɹű������书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  
   
   
   message_vision(HIM"$N����$nһ����У�"+me->name()+"�ڴˣ������ɹ�Ԫʦ������??\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(2);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}

void make_bs(object me, object ob)
{
   object obj, obj1;
   int exp,pot,kar;
	if (j>0){
 
        if (random(3) == 0)
        {
if (me->query("combat_exp") > 6000000)
{
	  obj = new(__DIR__"xueshan1");
	obj->set("title",HIR"�ɹŻ�������"NOR);
}
	}
       else
        if (random(3) == 1)
        {
if (me->query("combat_exp") > 6000000)
{
	  obj = new(__DIR__"xueshan2");
	obj->set("title",HIR"�ɹŻ�������"NOR);

}
	}
       else
        if (random(3) == 2)
        {
	  obj = new(__DIR__"xueshan3");
	obj->set("title",HIR"�ɹŻ�������"NOR);
	}
else{
obj = new(__DIR__"mengubing");
obj->set("title",HIG"�ɹ��ױ�"NOR);
}
//obj->set("id",me->query("id")+" "+obj->query("id"));
obj->set_name(obj->query("name"), ({ me->query("id")+obj->query("id")}));
         obj->move(environment(me));
	 obj->do_copy(me);
if (me->query_skill("jiuyin-zhengong",1) > 300)
{
        obj->set_temp("apply/attack", 200);
        obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 800);
        obj->set_temp("apply/damage", 300);
}

	if ( obj->query("id")=="weishi")
	{
	obj->set("title",HIG"�ɹ��ױ�"NOR);
	}
	  obj->do_copy(me);
         obj1 = new(__DIR__"mengubing");
//obj1->set("id",me->query("id")+" "+obj1->query("id"));
obj1->set_name(obj1->query("name"), ({ me->query("id")+obj1->query("id")}));
         obj1->move(environment(me));
 	  obj1->do_copy(me);
	obj1->set("title",HIY"�ɹ��ױ�"NOR);
          j=j-1;     
          obj->do_copy(me);
if (me->query_skill("jiuyin-zhengong",1) > 300)
{

        obj->set_temp("apply/armor", 800);
        obj->set_temp("apply/damage", 300);
}

          obj1->do_copy(me);
if (me->query_skill("jiuyin-zhengong",1) > 300)
{
        obj1->set_temp("apply/armor", 800);
        obj1->set_temp("apply/damage", 300);
}


          me->start_busy(1);
          }
else {
        message_vision(HIW"$N���Ѿ����˱��������ɹ�Ԫʦһ��ɱ�ˣ�\n"NOR, me);    
    if (me->query("kill_gumu") == 1) {
       message_vision(HIG"$NΪ������,�书���˽�չ��\n"NOR, me);    
   kar = random(me->query("kar")) * 10;
   if (kar > 550) kar = 550;
   exp = 650 + kar;
   
   exp=exp/2+188;
addnl(me,"exp",exp);
       me->set("kill_gumu",0);
       write(HIW"�����������,��Ц����,�ó�����.\n");
       write(HIR"�������ӳ����ɹž���Ӫ.\n"NOR);
       me->move("/d/xiangyang/southgate2");
       }
       ob->die();
    }
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
	remove_all_enemy();
        set("qi", 50000);
        set("eff_qi", 25000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("eff_qi", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("say ��ʦ����,�书��ʲô��??");
 message_vision(HIC "����shayuanshuai������\n" NOR,ob);
}

void fight_ob(object ob)
{
        ob->remove_killer(this_object());
        ob->remove_enemy(this_object());
        remove_killer(ob);
        remove_all_killer();
	remove_all_enemy();
        set("qi", 50000);
        set("max_qi", 25000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("neili", 8000);
        set("max_neili", 8000);
        ob->start_busy(6);
        command("say ��ʦ����,�书��ʲô��??");
        message_vision(HIC "����shayuanshuai������\n" NOR,ob);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�ɹ�Ԫʦ���˳�ȥ�������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"�����ﲻ����roar�ɣ�\n");
        return 1;
	}
}

int do_guard(string arg)
{
        write(this_player()->query("name")+"�������ڲ�����halt��\n");
        return 1;
}
