 // xiaojuan2.c
inherit NPC; 
void create()
{
        set_name("С��", ({ "xiao juan","juan" }) );
        set("title", "��Ů");
        set("gender", "Ů��" );
        set("age", 16);
        set("str", 1);
        set("per", 30);
        set("long", @LONG
С������������������ũ�Ķ���Ů������ʮ���꣬�˳���Ư���ִ󷽡�
С���Ѿ�����ĥ�ı������ˡ�
LONG
);
        set("max_jing", 500);
        set("eff_gin", 1);
        set("jing", 1);
        set("max_qi", 500);
        set("eff_qi", 1);
        set("qi", 1);
        set("max_sen", 500);
        set("eff_jing", 1);
        set("jing", 1);
        set("score", -500);     
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_skill("move",300);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
"С��˵�������� û�ϵ������Щ������һ��ģ�\n",
        }) ); 
        setup();
        
        carry_object(__DIR__"obj/torn_pink_cloth")->wear();
}  
int accept_fight(object me)
{
        command("say СŮ�����������Ķ��֣�");
        return 0;
}  
void init()
{
        object ob;
        if( interactive( ob = this_player()))
                        remove_call_out("followhim");   
        if (userp(ob)) {
        if((int) ob->query("marks/��������") == 1)
        {
        set_leader(0);
        call_out("goaway", 5);
        }
        else {
        call_out("messageing",3);
        call_out("followhim", 20, ob);
        }
        }
}
void messageing()
{
        object room;
        room = find_object(__DIR__"dungeon");
        if(environment() == room) {
        command("say ���ң��Ⱦ���ѽ��");
        command("emote ������������������������ѳ���������");
}
}
void followhim(object ob)
{
object room;
room = find_object(__DIR__"dungeon");
if(environment() == room)
if( present(ob, environment()) && userp(ob))
{       set_leader(ob);
        ob->set("marks/����", 1); 
}
} 
void goaway()
{
destruct(this_object());
} 
void die()
{
        int i;
        object killer; 
        if(objectp(killer = query_temp("last_damage_from")))
            killer->set("marks/murder", 1); 
        ::die(); 
}   
