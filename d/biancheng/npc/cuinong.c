#include <ansi.h>

 inherit NPC;
void create()
{
        set_name("��Ũ",({"cuinong"}));
        set("title",HIG"�߳�����"NOR);
        set("long","������Ҳ������̫������ȴ��˫��˵�����۾������ɵ��졣����Ȼֻ�Ǿ�������
�������ȴ��Ȼ���������˵ķ��˺����ʡ�һ��������Ů�ˣ����۶��κ�������
˵�����㹻����������������\n");
        set("gender","Ů��");
        set("age",22);
                
        set("str", 10);
        set("per", 60);
        
        set("combat_exp", 500000);
        set("attitude", "friendly"); 
        setup();
        carry_object("/clone/cloth/female-shoe")->wear();
} 
int accept_fight(object me)
{
        command("say СŮ�����������Ķ��֣�");
        return 0;
}
int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"����һ�����������Ŀ��ĵģ�");
        if((int)obj->value() >= 500000) me->add_temp("marks/chick2",1);
        return 1;
} 
void init()
{
        add_action("do_enjoy","enjoy");
} 
int do_enjoy()
{
object me;
object wo;
object *inv;
int maxgin,maxkee, maxsen;
int i;
        me = this_player();
        if((int)me->query_temp("marks/chick2") <=0)
        {
        command("say ��Ӵ��������λ" + RANK_D->query_respect(me) +
        "������û���;���ռ�˼ҵı���ô��");
        return 1;
        }
        me->add_temp("marks/chick2",-1); 
message_vision("$N��ƮƮ����$n�߹���������ĸ�Ū$n�ĺڷ�������\n",this_object(),me);
        me->unconcious();
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                if (inv[i]->query("no_drop") || inv[i]->query("owner")) continue;
                        destruct(inv[i]);
                }
        maxgin = (int)me->query("max_gin");
        maxkee = (int)me->query("max_kee");
        maxsen = (int)me->query("max_sen");
        me->set("eff_jing", maxgin);
        me->set("jing", maxgin);
        me->set("eff_qi", maxkee);
        me->set("qi", maxkee);
        me->set("eff_jing", maxsen);
        me->set("jing", maxsen);
        wo = new(__DIR__"obj/jade-hua");
        wo->move(me);
        return 1;
} 
