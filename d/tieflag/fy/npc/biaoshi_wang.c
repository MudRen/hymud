 inherit NPC;
int tell_him();
void create()
{
        set_name("����ʦ", ({ "wang", "biaoshi wang"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "�����ĸ��Ӳ��ߵ�һ������ӣ��൱�ؾ����ܸɡ�\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("hammer", 90);
        set_skill("dodge", 100);
        set("iron-cloth", 200);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ʦ����ʲô����ϳ�ʮ���ļ�Ǯ��\n",
                "����ʦ����ֱ��ţ��ұ�ƭ�ˣ�\n",
        }) );
    set("inquiry", ([
        "sword" : (: tell_him :),
        "����" : (: tell_him:),
        "�з�����" : (: tell_him:),
        ]));
        
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/jinzhuang")->wear();
        carry_object(__DIR__"obj/stonehammer")->wield();
} 
int tell_him()
{
    object me;
    me =this_player();
        if(me->query_temp("marks/sword_laowang")) {
                tell_object(me,"�������������㶼֪���ˣ����Ѿ��������ˣ������Ǹ������İ������ˣ�\n");
                me->set_temp("marks/sword_asked",1);
        }else{
                message_vision("$N�������Ϲ�£�û�е��£�\n",this_object());           
        }
    return 1;
}     
