 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("��������", ({ "old man", "man"}) );
        set("title", HIB"�׺�һ��"NOR);
        set("gender", "����" );
    set("age", 244);
    set("per", 65);
        set("int",28);
        set("attitude","friendly");
        
        set("neili",15000);
        set("max_neili",15000);
        set("max_qi",15000);
        set("max_jing",15000);
        set("jing",15000);
        set("qi",15000);
        set("force", 1000);
        set("force_factor",50); 
        set("long",
      HIW"һ�����¶��ҵİ׺������ߣ���ɫ����������ף�ͯ�պ׷����������ͼ\n���е���������һ�㡣������ϥ��Ŀ����������ŭ����\n"NOR
        );
        set("chat_chance", 1);
        set("chat_msg", ({
        name()+"��ʯ����ں����������˿��������Ȼ������\n",
        }) );
        
    set("combat_exp", 400000);
        
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 160);
        set_skill("unarmed",200);
    set_skill("changquan",200);
        set_skill("parry",200);
        
    map_skill("unarmed", "changquan");
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
