 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("С��", ({ "xiao bao", "bao" }) );
        set("title", HIG"������"NOR);
        set("gender", "����" );
        set("age", 23);
        set("str", 30);
        set("int", 25);
        set("cor", 30);
    set("long",
"���ߴ�Ӣ������׳����磬ϸ����Ũü�����ۣ����������Ե������� \n"
    );
        set("combat_exp", 300000+random(300000));
        set("attitude", "friendly");
        set_skill("move",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        //set_skill("perception", 100);
        set("max_neili", 500);
        set("chat_chance", 1);
        set("chat_msg", ({
                "С�������ֳϿҶ�ͬ���̬��˵�����������æ���ۣ��Ե����٣���ô�᲻�ݣ���\n", 
        }));
        setup();
        carry_object(__DIR__"obj/baocloth")->wear();
        //carry_object("/obj/armor/boots")->wear();
}    
