#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����ү", ({ "san ye", "xu san ye" }) );
        set("long",
                "һ��������ͷ����ȧӥ�ǡ������ܽ��������ɺܴ�������ˡ�\n");
        set("str", 25);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 400000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "����ү��˿ھƣ�����¶������ֵ�Ц�ݣ�ˣǹ���ˣ����������ڰ�\n��ǹ�£���Ҳ������һ�����¡�\n",
        }) );
        set_skill("unarmed", 70);
        set_skill("spear", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 50+random(50));
        set_temp("apply/move", 100);
        setup();
        carry_object(__DIR__"obj/spear")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
void init() { 
        ::init(); 
        if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
}    
