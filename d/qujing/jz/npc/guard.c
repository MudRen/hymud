//����̨����
//by junhyun@SK

#include <ansi.h>
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{

        set_name(HIG"����"NOR, ({ "guard" }) );
        set("race", "����");
        set("age", 3000);
        set("long", "�����������������ȥ�ġ�\n");
        set("str", 20);
        set("cor", 30);
        set("max_neili", 3000);
        set("neili", 5000);
        set("neili", 5000);
        set("max_neili", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_qi", 2000);
        set("max_jing", 2000);
        set("verbs", ({ "bite", "claw"}) );

        set("combat_exp", 1000000+random(1000000));
         set("combat_exp", 5000000);

 
        set_temp("apply/armor", 80);
        set_temp("apply/damage",80);
        set_temp("apply/armor_vs_force",300);
        set_weight(1000000);
        setup();
        initlvl((200+random(100)),1);
        //carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}


void init()
{
        ::init();
        add_action("do_cast", "cast");
        add_action("do_perform", "perform");
        add_action("do_bian", "bian");
        add_action("do_ji", "ji");

}

/*int do_dou()
{
        object me,who;
        me =this_object();
        who=this_player();

        if(me->is_fighting())
                return notify_fail("����������Ҫ����\n");
        message_vision("$N��$n��һ�������У�\n\n", who,me);
        me->kill_ob(who);
        who->kill_ob(me);
//        COMBAT_D->do_attack(me, who, query_temp("weapon"));
        me->set("owner",who->query("id"));
        return 1;
}
void die()
{
        string owner;
        object owner_ob;

        owner = query("owner");

        if(!owner) return ::die(); // added by mon.

        owner_ob= find_player(owner);

        if( owner_ob && (object)query_temp("last_damage_from") == owner_ob ) {
                owner_ob->add_temp("mark/��", 1);
                owner_ob->add_temp("mark/��", 1);
        message_vision("$N�ȵ����ݵò��񣬴��һؼ�ȡ���������㡣\n",this_object());
                destruct(this_object());
                return;
        }
        ::die();
}  */

int do_cast(string arg)
{
        object who = this_player();
        object me = this_object(); 
        message_vision("$N�ſ��죬���ɰɵ����˼������\n", who);
        message_vision ("$N��$nҡ��ҡͷ��\n", me, who); 
        return 1;
}        

/* int do_exert(string arg)
{               
        object who = this_player();
        object me = this_object();
        message_vision("$N��������һ������\n",who);
        message_vision("$N��$nҡ��ҡͷ��\n", me, who); 
        return 1;
} */

int do_perform(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N��ɫ����ԣ�������ɱ����\n", who);
        message_vision ("$N��$nҡ��ҡͷ��\n", me, who);  
        return 1;
}   

int do_ji(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N͵͵��������������ʲô������\n", who);
        message_vision ("$N��$nҡ��ҡͷ��\n", me, who);  
        return 1;
}

