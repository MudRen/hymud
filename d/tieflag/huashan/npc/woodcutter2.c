 // woodcutter.c
inherit NPC;
int milin();
void create()
{
        set_name("�Է�", ({"woodcutter"}) );
        set("gender", "����" );
        set("age", 36);
        set("agi",30);
        set("per", 10);
        set("str",100);
        set("long",
                "һ��������Է����ڳ���Ŀ���ʹ������һ˫�ֲ������ϼ롣\n"
                );
        set("max_jing", 1000);
        set("max_qi", 1000);
        set("max_sen", 1000);
        set("combat_exp", 20000);
                set("inquiry", ([
                        "milin" : (: milin :),
                        "����" : (: milin :),
                        "����" : (: milin :),
                ]));
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
        set_skill("axe",50);
            setup();
            carry_object(__DIR__"obj/woodaxe")->wield();
            carry_object("/clone/misc/cloth")->wear();  
} 
int milin(){
        object me;
        me = this_player();
        message_vision("$Ņͷ����$nһ�۵�������Ƭ��������Ҳ�߲�����ÿ�ζ�ת�ص�����ҿ�Ҳֻ��
��ɵ����֪�����ֺ�����ʲô��\n", this_object(), me);
        return 1;
}    
