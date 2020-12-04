// �� /d/city/chuzhou/npc/zuihan.c
// by lala, 1997-12-14
inherit NPC;
 
void do_drink();
 
void create()
{
    seteuid(getuid());
    set_name("��", ({"zui han", "han", "drunk"}));
    set("long", @TEXT
����һ���ȵ���������ĺ��ӡ�    
TEXT
    );
    set("gender","����");
    set("age",37);
    set("con",30);
    set("str",30);
    set("water", 0);
    set("combat_exp",100);
    set("attitude","heroism");
    set("chat_chance",15);
        set("qi",400);
        set("max_qi",400);
        set("eff_kee",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_sen",400);
    
    set("chat_msg", ({
    (: do_drink :), }) );
    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/d/city/npc/obj/wineskin");
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
    if (can_drink) 
    {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop wineskin");
    }
    else {
        command("sigh");
        command("say ���ơ������Ҿơ�����");
        command("say ���ҡ�����û��û����������");
    }
    return;
}
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say ���յ��Ҳ�Ҫ������");
            return 0;
        }
        else {
            command("smile");
            command("say ����л����");
            return 1;
        }
    }
    else return 0;
}
 
