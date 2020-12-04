 inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("�˷�����", ({"xiansheng", "xian", "xian sheng"}));
        set("long",
                "һ�������ܸɣ��书��ǿ���˷�����\n");
        set("gender","����");
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 300);
        set("neili", 300);
        set("max_mana", 300);
        set("mana", 300);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 9999999);
        set("no_heal",1);
        
        set("can_carry", 1);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70); 
        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
        set_skill("fall-steps", 100); 
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
        }) ); 
        set("chat_chance",3);
        set("chat_msg", ({
        (: do_drink :), }) );
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop wineskin");
    }
    else 
message_vision("$N��������������Ϊ��ƶ�����ı��ӣ�\n", this_object());
    return;
}
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say �յ��Ҳ�Ҫ...");
            return 0;
        }
        else {
            command("smile");
            command("say ��л!");
            return 1;
        }
    }
    else return 0;
}
       
