#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����˾ͽ", ({ "jiangzuo situ","situ" }) );
        set("gender", "Ů��" );
        set("long",
"һ�����¸��ˣ�����ȥ���Ŀ�ƣ�����Լ����һ˿���죬Ҳ¶��һ������\n�����գ��˿����������ʹ֮ɫʹ��רΪ�������ѡ�������ˡ�\n" 
                );
        create_family("�����", 1, "ɫʹ");
        set("attitude", "peaceful");
        set("class", "bat");
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"blade.shiwanshenmo":),
                      (:perform_action,"dodge.huanyingqianchong":),
        }));
        set("age", 65);
        set("cps", 40);
        set("int", 10);
        set("per", 4);
        set("cor", 40);
        set("agi", 30);
        
        set("combat_exp", 1000000);
        set("force", 1000);
        set("max_force", 1000);
        
        set_temp("apply/armor",50);
        set_temp("apply/damage",30);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˾ͽ˦��˦��������������Ц��Ц�㿴���㡣\n",
                }) ); 
        set_skill("unarmed", 150);
        set_skill("blade", 150);
        set_skill("bat-blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("move", 300);
        set_skill("meng-steps", 120);
        set_skill("nine-moon-claw", 120);
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup(); 
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
} 
void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
} 
int greeting(object ob)
{       
        object room;
        if ((string)ob->query("gender") == "Ů��" )
        {
            if( ((int)ob->query_per() >= 20) && ((int)ob->query("age") <= 30)
                && ob->query("class")!="knight" && ob->query("combat_exp") < query("combat_exp"))
                {
                        if(!objectp(room = find_object("/d/loulan/zhenchunyuan")))
                                room = load_object("/d/loulan/zhenchunyuan");
                        message_vision("$N��һ�ۣ���һ����ϸ����$n�����¶���������Ц�ݡ�\n",this_object(),ob);
                        message_vision("$N��������С���˶�����үҪ�ǿ����㣬�����㼸����Ҳ�޲����ĸ�����......\n",this_object());
                        message_vision("$N��ָһ�ӣ�һ��Ũ����$n�˱Ƕ�����\n",this_object(),ob);
                        ob->unconcious();
                        ob->move(room);
                }
                return 1; 
        }
   else
                return 0;
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")==HIY "�����ͺ�ɢ"NOR )
        {
                message_vision("$N����������ү���¿ɲ��ó��ˣ�����������ң�ҲҪ�Թ������Ҽ���ү��\n",this_object(),this_player());
                who->set_temp("marks/give_jiangzuo_hehesan",1);
                return 1;
        }
        else
        {
        message_vision("$Nҡͷ˵���������ʲô�������ҿ��޸����ܡ�\n",this_object()); 
                return 0;
        }
}       
