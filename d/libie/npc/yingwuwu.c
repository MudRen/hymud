#include <ansi.h>
inherit NPC;
int answer_robery();
int answer_di();
int answer_yang();  
void create()
{
        set_name("Ӧ����", ({ "ying wuwu","ying","wuwu" }) );
        set("long",
                "һ��������������Ϲ�ӣ���ͷ������ɫ���·����ǻ����˵���ɫ��\n"); 
        set("attitude", "friendly");
        set("age",49);
        set("str", 80);
        set("cor",80);
        set("agi",70);
        set("cps",65);
        set("con",80);
        set("nickname", HIG"�Ŀ��"NOR); 
        set("combat_exp", 2500000+random(2500000));
        set("max_neili",3000);
         
        set_skill("unarmed",200);
        set_skill("sword",200);
        set_skill("softsword",200);
        set_skill("parry",700);
        set_skill("dodge",700);
        map_skill("sword","softsword"); 
/*        set("chat_chance", 1);
        set("chat_msg", ({
"����ү��ҵ�����������߻ص����������ú�ԩ�š�������\n"
}) ); 
        set("inquiry", ([
                "���ڰ�" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "���" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "������" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ])); 
*/
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
} 
void heart_beat()
{
        ::heart_beat();
        if(query("sad_leave"))
                call_out("sad_leave",2);
} 
int do_busy(object who)
{
        object room,ying,yang,hook,sword;
        
        ying=this_object();
        room=environment(ying);
        if(!present(who,room)) return 0;
        if(who->query_skill("move",1)>99&&(hook=present("leave hook",who))&&(yang=present("yang zheng",room)))
        {
                message_vision(HIR"Ӧ����������һ������$N����������ס$N������Ѩ����$N����һ�ӡ�\n"NOR,who);
                message_vision(HIM"��$N�ڵ���֮ǰ���þ����һ˿������������Ӹ����\n"NOR,who);
                yang->set_temp("����𹳵���",who);
                hook->move(yang);
                if(sword=present("sword",yang))
                        if(sword->query("equipped"))
                yang->ccommand("unwield sword");
                yang->ccommand("wield leave hook");
                message_vision(WHT"$N��$n���ʾ�⣺����л��λ"+RANK_D->query_respect(who)+"Ϊ���������С���\n",yang,who);
        }
        else
        {
                message_vision(HIR"Ӧ����������һ������$N����������ס$N������Ѩ����$N����һ�ӡ�\n"NOR,who);
                message_vision(HIR"Ӧ������Цһ��������������������ÿ�ν��⣬�ֶ��˸�������һ�̡���\n\n\n"NOR,who);
        }
        who->start_busy(100000);
        ying->set("busy_object",who);
        
} 
void sad_leave()
{
        message_vision("Ӧ���ﳤ̾һ��������ֽ��������������𹳴���֮�֣�ʱҲ����Ҳ����ת����ȥ��\n",this_object());
        destruct(this_object());
}   
