// dtz.c

inherit NPC;
int random_action();
void create()
{
        set_name("��ū", ({ "guinu" }) );
        set("gender", "����" );
        set("age", random(25)+15);
        set("long", "һ��Ϊ����԰Ч�������ڿ��ŵĹ�ū\n");
	set("per",30);
        set("combat_exp", 800000);
	set("no_arrest",1);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set_skill("parry", 200);
	set_skill("dodge", 200);
        set("chat_chance", 2);
        set("chat_msg", ({
                (: random_action :)
        }) );



	setup();
//	add_money("gold", 1);
        carry_object("clone/cloth/cloth")->wear();
        
}

int random_action()
{
int permit;
permit=(int) environment(this_object())->query("enter_permission");
	if(!permit)
switch(random(5)){
	case 0:
		command("zzz");
		break;
	case 1:
		command("yawn");
		break;
	case 2:
		command("bored");
		break;
		}
	else
switch(random(5)){
        case 0:
message_vision("$N�����죬������������԰�Ĺ��ȫ�����ģ�\n",this_object());
                break;
        case 1:
message_vision("$N�������㼸�ۣ���Ǯ���Ǵ�ү�������ϳ���԰�ż䣡\n",this_object());
                break;
                }

}
