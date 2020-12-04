 
// killer.c
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "figure" }) );
        set("long",
"�����ͷ�ϴ�������ͷ�֣��˳�׼����ʲ�ỵ�¡�\n");
        set("attitude", "heroism");
        set("hired_killer", 1);
        set("age",random(10)+30);
        set("max_qi",1500);
        set_skill("dodge",90);
        set_skill("sword",90);
        set_skill("taiji-jian",90);
        map_skill("sword","taiji-jian");
        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :),
        }));
        set("combat_exp",50000+random(50000));
        setup();
        carry_object("/clone/misc/cloth");
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
          call_out("move_killer", 900);
          call_out("learn_skill",1);
          add_action("do_arrest","arrest");
}
void learn_skill()
{
        object ob, me;
        mapping skill_status, map_status, hp_status;
        string *sname, *mname;
        int i;

        me = this_object();
        ob = this_player();
        if (me->is_fighting() || wizardp(ob)) return;

        remove_call_out("learn_skill");

        me->map_skill("unarmed");
        me->map_skill("dodge");
        me->map_skill("parry");

        if ( !(skill_status = ob->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++) {
                me->set_skill(sname[i], skill_status[sname[i]]);
        }

        if ( !(map_status = ob->query_skill_map()) ) return;
        mname  = keys(map_status);

        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }
       hp_status = ob->query_entire_dbase();
       call_out("learn_skill", 3);
}
int do_arrest(string arg)
{
   mapping job;
   object ob = this_player();
   object who;
   job = ob->query("job");
   if( !job || job["job_type"] != "ץ")
     return notify_fail("�㲻�ǹٲ����ץ��참��\n");
   if(!arg)
   return notify_fail("����ץ˭��\n");
   if(!objectp(who = present(arg, environment(ob))))
   return notify_fail("����û������ץ���ˡ�\n");
   message_vision("$N����һ�������ӣ�������...\n",ob); 
   message_vision("����$N�����ȵ����������ˣ������������ӣ��������ɣ���\n",this_object());
   ob->set_temp("arrest",1); 
   this_object()->kill_ob(ob);
   return 1;
} 

void move_killer()
{
    message_vision("$N�Ҵ���ȥ�ˡ�\n",this_object());
    destruct(this_object());
    return ;
}
void unconcious()
{
     object killer;
     killer = query_temp("last_damage_from");
     if(killer->query_temp("arrest"))
     set("end_job", killer->query("id"));
     remove_call_out("learn_skill");
     ::unconcious();
     return ;
}

