#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("�׷ɷ�", ({ "bai feifei","bai" }) );
        set("gender", "Ů��" );
        set("title", "���鹬��" );
        set("nickname", HIB"�쳾�о����޳�"NOR );
        set("long",
                "һ���㷢���ƣ���ɢ˫��İ�����Ů����������̬֮�������ҡ�������\n�����羧Ө����˫��Բ���޳���������ů������΢΢����š����� \n"
                );
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"dodge.lianhuanbu":),
                      (:perform_action,"unarmed.suicidal":),
              })      );
        set("age", 25);
        set("str", 20);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 600000);
        set("force", 2000);
        set("max_force", 2000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        set("force_factor", 50);
        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�׷ɷɷ������������ϣ������������Ƶ�����һ�������ƣ�������������\n���ӣ�����ô����һ���ˣ����������Ҫ���裬���Ҫ��������\n",
                "�׷ɷ�֧�������Գ�Ц������������ֱ�������塢�ǻ���ߵ����ˣ���������а\n��������ǻ�Ҳ��ߵ�Ů�ˣ������������ĺ��ӣ��ֻ�������һ���ˣ� \n",
                }) ); 
        set_skill("unarmed", 150);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("move", 300);
        set_skill("nine-moon-steps", 150);
        set_skill("nine-moon-claw", 150);
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        setup();
        carry_object(__DIR__"obj/baisha")->wear();        
        
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int greeting(object me)
{
        object *inv;
        int i;
        int j;
        object ob;
        j = 0;
        ob = this_object();
        if( !me || environment(me) != environment() ) return 1;
        if( userp(me) && me->query_temp("marks/chai_get_command"))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="������" && (int)inv[i]->query("equipped"))
                        {
                                message_vision("$NŤ��������$n������������֪���ˣ����ȥ��\n",this_object(),me);
                                call_out("leave",10,me);
                                j = 1;
                   }
                }
                if ( j==1 )
                {
                        message_vision(HIY"$N����Ц�����㣬���뿴������������\n"NOR,ob);
                }
        }
        return 1;
} 
void leave(object me)
{
        object ob;
        if (living(this_object()) && environment(me) == environment())
        {
                if (ob=present("shen lang", environment(this_object())))
                {
                        message_vision("$N������$n˵�������뿪�ᣬ����������Ҫ���ɱ𲻸�˵����\n",this_object(),ob);
                        message_vision("$N��ȻһЦ�����ϳ�ȹ������Ц���뿪������ \n",this_object());
                        me->set_temp("marks/chai_notify_bai",1);
                        me->delete_temp("marks/chai_get_command",1);
                        destruct(this_object());
                }
                else
                {
                        message_vision("$N���ϳ�ȹ������Ц���뿪������ \n",this_object());
                        destruct(this_object());
                }
        }
        else
                remove_call_out("leave");
} 
