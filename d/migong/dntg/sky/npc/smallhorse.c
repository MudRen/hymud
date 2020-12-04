#include <ansi.h>
#include <dbase.h>

inherit NPC;

void create()
{
  set_name("С���", ({ "ma ju", "ju" }) );
  set("race", "Ұ��");
  set("age", 5);
  set("long", "һֻ��δ�����С��ԡ�\n");
  set("per", 10+random(20));
  set("qi", 100);
  set("max_qi", 100);
  set("jing", 100);
  set("max_jing", 100);
  set("combat_exp", 4000);
  set("daoxing", 4000);

  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("ride/msg", "ǣ");
  set("ride/dodge", 20);
  set("verbs", ({ "bite"}));

  set("chat_chance", 10);


  setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);

        set("chat_msg", ({
            "С�������ĺߺ��˼�����\n",
            "С���Ħ����ǰ�㡣\n",
            "С���һ���޾���ɵ����ӡ�\n",
        }) );

        add_action("do_qian", "qian");
        add_action("do_mount", "mount");
}

int do_qian(string arg)
{
        object me = this_object();
        object who = this_player();


        if (arg != me->query("id"))
         return 0;


        else 
            { 
            if (who->query("qi")>50)  who->add("qi",-50); 
            else
               {
               who->unconcious();
               return 1;
               }

            if ( me->query("qi") == 100)
                {

                if ( random(20) != 0 )
                message_vision("$Nǣ��С�������һȦ��\n", who);

                else
                     {
                     object smallhorse;
                     message_vision("$Nһ��˻�������㼲����\n" , me,);
                     me->add("max_qi",200);
                     me->add("eff_qi",200);
                     me->add("qi",200);
                     }
                }
            else  message_vision("$Nǣ��С�������һȦ����С�����Ȼ�޾���ɡ�\n", who);

             }
        return 1;

}

int do_mount(object me)
{
        object who = this_player();
        me = this_object();

        if (me->query("qi")<200)  
           {
            message_vision("С��Բҽ�һ�����ʵ��ڵء�\n\n", me);
            me->unconcious();
            return 1;
           }
}

�