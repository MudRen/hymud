#include <ansi.h>
inherit NPC;   
void create() 
{ 
        set_name("��׼", ({ "chen zhun","zhun"}) ); 
        set("title",  "����կ �����" );
        set("nickname",HIC "���ƽ"NOR);
        set("gender", "����"); 
        set("age", 53);
        set("long", 
                "��׼�Ǹ�����С���ˣ����þ��������ִ���Ҳû������ʴ����������\n����һ�������ϲ�ЦʱҲ���Ǵ��Ź�Ц�Ƶ�\n"); 
        set("combat_exp", 430000);
        set("score", 1000);
        set("attitude","friendly");
        set("bellicosity", 200);
        
        set("max_neili", 1000);
        set("force", 1500);
        set("force_factor", 10); 
        set("int",30);
        set_skill("force", 60);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("changquan",500);


        map_skill("unarmed","changquan"); 
        setup(); 
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
        add_money("gold", 1); 
}   
void init() 
{ 
        object me; 
        ::init(); 
   me = this_player();
        if(me && environment(me) == environment() && !me->is_fighting()) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }   
}   
void greeting(object me) 
{ 
        if((string)me->name() !="��ɽ��" ) 
        {
                command("say �ٺ٣�������·�㲻�ߣ�������������Ͷ����ȭ��\n");
                this_object()->kill_ob(me);
        }
        else if ((string)me->name() =="��ɽ��")
        {
                message_vision("$N�����۾�����$n���˰���......\n",this_object(),me);
                if((int)me->query("kar")+random(50) < 30 )
                {
                        message_vision("$N�����������������˱����������ң������ߣ���\n",this_object(),me);
                        this_object()->kill_ob(me);
                }
        }
}     
