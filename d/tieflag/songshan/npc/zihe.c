 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("ȸ�Ӻ�", ({ "zihe" }) );
        set("gender", "����" );
        set("age", 35);
        set("title", HIW "˫�Ʒ���"NOR);
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("intellgent",1);
        set("fly_target",1);
        set("chat_chance", 1);
        set("chat_msg", ({
//                (: random_move :),
                "ȸ�Ӻ��૵���������ѽ�������㣡��������������ӣ�\n",
        }) ); 
        set("long",     "�������˳ƣ�˫�Ʒ��죢��ȸ�Ӻ�\n");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "dodge.liushuichanchan" :) 
        }) );
        set("combat_exp", 3299999);
        set_skill("unarmed", 120);
        set_skill("dodge", 100);
        set_skill("yunwu-strike", 380);
        set_skill("liuquan-steps", 370); 
        map_skill("unarmed", "yunwu-strike");
        map_skill("dodge", "liuquan-steps"); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}      
