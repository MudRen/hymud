 // dtz.c
inherit NPC; 
void create()
{
        set_name("��ͽ��", ({ "dtz" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "һ��ɫ���Եĵ�ͽ��.\n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("chat_chance", 2);
        set("chat_msg", ({
                (:random_move :),
        "��ͽ�ӵ�����˵ǧ�����Ӱﵱ��͢����һ���󰸡�\n",
        "��ͽ�ӵ����ҳ��ɵ����Դ�����Ϲ�֣�û��һ��׼�ġ�\n",
        }) ); 
        set("inquiry", ([
                "��" : "�����ȻʵĴ̿ͱ�ͬ��ıɱ��ʬ��ǧ������ֻ�ô̿͵�ͷ�ǾͿ��������̿͵���ߣ�\n",
                "case" : "�����ȻʵĴ̿ͱ�ͬ��ıɱ��ʬ��ǧ������ֻ�ô̿͵�ͷ�ǾͿ��������̿͵���ߣ�\n",
         ]));
        setup();
        add_money("coin", 1);
        carry_object("/clone/misc/cloth")->wear();
        
}  
void die() {
        message_vision("haha i die.\n",this_object());
        destruct(this_object());
        message_vision("haha i die again.\n",this_object());
}      
