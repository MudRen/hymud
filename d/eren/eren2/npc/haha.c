#include <ansi.h>
inherit NPC;  
int give_mission(); 
void create()
{
        set_name(HIY"�油"NOR,({"guardian"}));
        set("nickname","Ц��ص�");
        set("long", "���˰������֣�Ц��ԲԲ�������Ǹ��������ƵľƵ��ƹ񡣡�\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4000000);
                        
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1500);
        set("neili",1500);
                
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "����" : (: give_mission :),
                "ԭ��" : (: give_mission :),
                "��������" : (: give_mission :),
                "ŷ��������" : (: give_mission :),
                "ŷ����" : (: give_mission :),
                "ŷ����" : (: give_mission :),
                "ouyang ding" : (: give_mission :),
                "ouyang dang" : (: give_mission :),
                "С��" : "�����С�������컹����������š�",
                 "������¥": "������¥��Ȼ���ҿ���ඡ�",
                 "������ջ": "������ջ����������Ů�����ġ�",
                "��С��": "������ջ����������Ů����С�����ġ�",
                "���˹�": "����˹���������û�����ˡ�",
                "������": "�����������˭�˲��������ﻹ�����������ء�",
                "����": "����ҽ����������֮�ܡ�",
                "���ϵ�": "���ϵ�ר��������˵Ҫ�����İ���������ѧ������������С�",
                "��ԯ����": "�����ֻʣ���Ǽ䵱���ˡ�",
                "ɽȸ��": "֪���һ�Ҫ���æ��",
                   "��ɽ����": "֪���һ�Ҫ���æ��",
                "ɳ���": "֪���һ�Ҫ���æ��",
                "����": "֪���һ�Ҫ���æ��",
        ])); 
                
        set("chat_chance", 1);
        set("chat_msg", ({
                "Բ������Ц��������̨Զ������ض��ˣ�������Щ��������̸���¡���\n",
                "������ƤЦ�ⲻЦ�ص������������������ҹ����������\n", 
                "��������ü������˵������������˺ö࣬���������������Ķ������ӡ���\n",                         
        }) );

        set_name("������",({"haha er"}));
        set("force_factor",60);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        message_vision("$NЦ�������˹���������Ц��������̨Զ�������ˡ���\n", this_object() );
           return;
}  
int give_mission() {
        object me,ob;
        
        ob=this_object();
        me=this_player();
        
        if (me->query("marks/���˿�",1)) {
                message_vision("������ƤЦ�ⲻЦ������$n������˵����˵��������������\n",ob,me);
                return 1;
        }
        
        if (me->query_temp("eren/haha_1")||me->query_temp("eren/haha_2")
                ||me->query_temp("eren/haha_3")) {
                tell_object(me,"���������������˵������ô���������˹�����\n");
                return 1;
        }
        message_vision(CYN"$N̾�˿���˵:���ⲻ���������Թ�ֻ��˵��������ʩ��û�뵽��������
Ҳ��ô��������������˿�Խ��Խ���ˡ�\n"NOR,ob);
        tell_object(me,"������С��˵���͹��Ƿ��ܰ�С�Ĺ�һ��Сæ��\n"); 
        tell_object(me,"������˵��Ҳ���Ǹ�Щԭ�ϣ�������Կ�ɽ�������Ƿ���Ū������\n\n");       
        me->set_temp("eren/haha_1",1);
        return 1;
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")=="��ɽ����" && who->query_temp("eren/haha_1"))
        {
                command("spank "+who->query("id"));
                if (!who->query("eren/haha_1")) {
                        who->add("potential",100);
                        who->add("combat_exp",1000);
                        who->set("eren/haha_1",1);
                        tell_object(who,WHT"�㱻�����ˣ�һ��Ǳ�ܣ�һǧ����ֵ��\n"NOR);
                }
                message_vision("$N˵:�����Ҹ�Щɽȸ��ɡ�\n",this_object());
                who->set_temp("eren/haha_2",1);
                return 1;
        }
   if (ob->query("name")==HIG"ɽȸ��"NOR && who->query_temp("eren/haha_2")
                && who->query("eren/haha_1"))
        {
                command("spank "+who->query("id"));
                if (!who->query("eren/haha_2")) {
                        who->add("potential",100);
                        who->add("combat_exp",1000);
                        who->set("eren/haha_2",1);
                        tell_object(who,WHT"�㱻�����ˣ�һ��Ǳ�ܣ�һǧ����ֵ��\n"NOR);
                }
                message_vision("$N˵:�����Ҹ�Щ"+YEL"����"NOR+"�ɡ�\n",this_object());
                who->set_temp("eren/haha_3",1);
                return 1;
        }
        if (ob->query("name")==YEL"����"NOR && who->query_temp("eren/haha_3")
                && who->query("eren/haha_1") && who->query("eren/haha_2"))
        {
                command("spank "+who->query("id"));
                if (!who->query("eren/haha_3")) {
                        who->add("potential",100);
                        who->add("combat_exp",1000);
                        who->set("eren/haha_3",1);
                        tell_object(who,WHT"�㱻�����ˣ�һ��Ǳ�ܣ�һǧ����ֵ��\n"NOR);
                }
                message_vision("$N˵:�ã��ã������ܸ㵽ɳ��Σ���һ���ܰ����ӱ���ȥ��\n",this_object());
                message_vision("$N˵���ұ�����л��������$N��$n���˻��֡�\n",this_object(),who);
                who->set_temp("eren/haha_4",1);
                return 1;
        }       
        if (ob->query("name")==YEL"ɳ���"NOR && who->query_temp("eren/haha_4")
                && who->query("eren/haha_1") && who->query("eren/haha_2")
                && who->query("eren/haha_3"))
        {
                command("ack "+who->query("id"));
                message_vision("$N���Ͱ͵�˵��������������Ź���������\n",this_object());
                who->set("marks/���˿�",1);
                who->delete_temp("eren/haha",1);
                who->delete_temp("eren/haha",2);
                who->delete_temp("eren/haha",3);
                who->delete_temp("eren/haha",4);
           tell_object(who,"���������������˵������������Ļ��ܣ���������������ű���������ˡ�\n",this_object());
                command("grin");
                return 1;
        }       
        return 0;       
}     
