#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("������", ({"liu yaomei","yaomei"}) );
        set("gender", "Ů��" );
        set("nickname", HIM"ɫ��"NOR);
        set("long", "����һ��������⣬����΢¶��������Ů��ɫ���Եض����㡣\n");
        set("attitude", "friendly");
/*      set("max_jing", 400);
        set("max_qi", 400);
        set("max_jing", 400); */
        set("age", 18+random(10));
//      set("str", 18);
        set("cor", 22);
        set("per", 28);
        set("cps", 20);
        set("combat_exp", random(600000)+200000);
        create_family("��ɽ", 4, "����");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        set("chat_chance", 1);
        set("chat_msg", ({
        "�����ÿ���Ц�����������ﲻ������ĥ��Щ��ô������ū�����ү���ȴ����ɣ�\n",
        }) );
        setup();
        carry_object(__DIR__"obj/pink_cloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        object *inv;
        int i;
        if ((string)ob->query("gender") == "����")
        {
        message_vision("$N������˿����$n��˫��Ħ�����Լ��⻬���ظ�����߽��������ɰ�����ѽ��\n��ѽ�������ҹ�������֮�֡�����\n", this_object(),ob );
        if ((int)ob->query("con",1)<random(15) && !ob->query_temp("sleeped")){
                        message_vision("$N������ˮֱ���������Ϳ������ȥ��\n", ob);
                        ob->set_temp("sleeped",1);
                        ob->set_temp("disable_inputs",1);
                        ob->set_temp("block_msg/all",1);
                        ob->set_temp("is_unconcious",1);
                        ob->set("disable_type",HIG "<˯����>"NOR);
                        inv = all_inventory(ob);
            for(i=0; i<sizeof(inv); i++) {
                                if(inv[i]->query("owner") || inv[i]->query("no_drop")) {
                                } else {
                                        destruct(inv[i]);
                                }
                        }
                        call_out("wake", 8, ob);
                        return;
                }
                else
                {
                        message_vision("$Nŭ��һ������Ů��������\n", ob);
                        return;
                }
          }
          return;
} 
void wake(object ob)
{
        ob->delete_temp("disable_inputs");
    ob->delete_temp("sleeped");
        ob->delete("disable_type");
        ob->delete_temp("block_msg/all");
        ob->delete_temp("is_unconcious");
        if(!ob->is_ghost())
        {
        message_vision("$N�������۾����پ����������ವģ���ͷһ�������ڿ㶼û�ˡ�\n", ob); 
        message_vision("$N���ᴩ����ȹ����������ū��ʲô�����˹��ӣ������㡭��Ҫ��ū�Ҹ����ϡ�\n",this_object());
                return;
        }
        return;
}       
