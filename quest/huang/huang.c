// huang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "huangjobhy.c"
int ask_wldh();
void create()
{
    set_name("����", ({"huang rong", "huang", "rong"}));
    set("gender", "Ů��");
    set("age", 36);
    set("long", "���Ǳ��������ķ��ˣ���а��ҩʦ�İ�Ů��ǰ��ؤ�������\n");

    set("attitude", "peaceful");
    set_max_encumbrance(200000000);   
    set("per", 30);
    set("str", 300);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 8000);
    set("max_qi", 8000);
    set("jing", 8000);
    set("max_jing", 8000);
    set("neili", 20000);
    set("max_neili", 20000);
    set("jiali", 0);
       
    set("combat_exp", 5000000);
    set("score", 0);
       
    set_skill("force", 320);
    set_skill("bibo-shengong", 320);
    set_skill("unarmed", 320);
    set_skill("luoying-zhang", 320);
    set_skill("dodge", 180);
    set_skill("anying-fuxiang", 320);
    set_skill("parry", 120);
    set_skill("sword", 120);
    set_skill("luoying-shenjian", 320);
    set_skill("qimen-wuxing", 320);
    set("inquiry", ([
		 "job"   : (: ask_job :),
         "����"  : (: ask_gonglao :),
         "���"   : (: ask_jobover :),
         "over"   : (: ask_jobover :),
         "fangqi": (: ask_fangqi :),
         "����"  : (: ask_fangqi :),
         "���ִ��" : (: ask_wldh() :),
		 ]));      
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
       
    create_family("�һ���", 2, "����");
    setup();
    carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
    carry_object("/kungfu/class/taohua/obj/shudai")->wear();

}

int ask_wldh()
{

        object me = this_player();
        object ob,where,who,fang;
        mapping quest;
        mapping skl; 
        string *sname, place;        
	
        int i, skill = 0;
	
        ob=this_object();
        who=me;
        where = environment(who);
        if(((int)me->query("jinyong/book10")!=2))
           {
                      message_vision("$N����$n˵�������û���п����ִ�ᡣ\n", this_object(), me);
	                      return 1;
            }


        if(where->query("short")!="������԰")
           {
                      message_vision("$N����$n˵���������޷��п����ִ�ᡣ\n", this_object(), me);
	                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�㻹�����߾���������");
                return 1;
}
 
 
         fang = present("jinlun fawang",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "���ȶԸ����˰�");
                return 1;
	}

         fang = present("daerba huofo",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "���ȶԸ����˰�");
                return 1;
	}

         fang = present("huo du",where);
	if(fang)
	{
                command("say " + RANK_D->query_respect(me) + "���ȶԸ����˰�");
                return 1;
	}

        if (ob->query_temp("wldh") && !me->query_temp("book1033") && !me->query_temp("book1032") && !me->query_temp("book1031")) {
                command("kick " + me->query("id"));
                command("say ���ִ��ſ�������");
                return 1;
                }
if (!ob->query_temp("wldh")) {
                ob->set_temp("wldh",1);
fang = load_object("/kungfu/class/xueshan/huodu");
	fang->move(environment(who));	
fang = load_object("/kungfu/class/xueshan/daerba");
	fang->move(environment(who));	
fang = load_object("/kungfu/class/xueshan/fawang");
	fang->move(environment(who));			

                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "���ִ�ᣬ���Ͼ�Ҫ���ˣ���������һЩ�ɹ��߹������ܰ��Ҵ�������?");
	tell_object (me,"����,�����,���ַ���ɱ�˽�������\n");

return 1;
}

        if (!me->query_temp("book1033")) {
                command("kick " + me->query("id"));
                command("say ���Ӯ���ַ�������");
                return 1;
                }
	
        if (!me->query_temp("book1032")) {
                command("kick " + me->query("id"));
                command("say ���Ӯ���������");
                return 1;
                }
                
        if (!me->query_temp("book1031")) {
                command("kick " + me->query("id"));
                command("say ���Ӯ��������");
                return 1;
                }



  	if(((int)me->query("jinyong/book10")==2))
	{
		
 	i = 1200+random(2900);
	me->set("jinyong/book10",3);
	me->add("combat_exp",i+12880);
	me->add("potential",i*18);
	me->add("mpgx",10);
	me->add("expmax",3);

	tell_object (me,"��Ӯ����"+chinese_number(i+12880)+"�㾭��"+
	           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		
         }
                command("thank " + me->query("id"));
                command("say " + me->query("id") + "������ִ������һ��Ҫ����ɹ��ˣ�" NOR);
                command("say " + me->query("id") + "��˵����һ���˵������ȥ�ˣ�" NOR);

                return 1;
                             
}