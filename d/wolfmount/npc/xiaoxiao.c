#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��С��", ({"xiaobu"}) );
        set("gender", "����" );
        set("nickname", HIG "����"NOR);
        set("long", "һ�����㴩��˫��Ь��ͷ���ҵ����ѵ����ꡣ\n");
        set("attitude", "friendly");
/*      set("max_jing", 300);
        set("max_qi", 300);
        set("max_jing", 300); */
        set("age", 15+random(5));
        set("str", 20);
        set("cor", 10);
        set("cps", 15);
        set("combat_exp", random(100000)+100000);
        create_family("��ɽ", 1, "���Ĵ�����");
        set_skill("blade", 40+random(10));
        set_skill("parry", 40+random(10));
        set_skill("dodge", 40+random(10));
        set_skill("move", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
        "��С���ԳԵ�Ц�ţ���ϲ�����ÿ���Ů�ˣ���ϲ���ͺÿ���Ů�ˡ�����\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/shorts")->wear();
        carry_object(__DIR__"obj/shoes")->wear();
} 
void init()
{
        object conch;
        ::init();
        if( ! this_object()->query("given") )
        {
                this_object()->set("given",1);
                if (!random(3))
                {
                        conch=new(__DIR__"obj/conch");
                   conch->move(this_object());
                        return;
                }
                else
                {
                        say("��С���ḧ�����������߽����������\n");
                        return;
                }
        }
        return;
} 
