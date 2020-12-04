#include <ansi.h>
#include <command.h> 
inherit NPC;
void do_drink(); 
void create()
{ 
        set_name("��",({"drunk"}));
        set("age",37);
        set("combat_exp", 5000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        
        set("pursuer", 1);
        set("parrot_killer",1);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("death_msg",CYN"\n$N˵�����ˣ��ܵ������ٶ���ʲô�á��� \n"NOR);
        set("chat_chance",1);
        set("chat_msg", ({
           (: do_drink :), }) 
        );
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\nɱ��˵������ʲô�¶����ܣ�ֻ��ɱ�ˣ�����\n",
        ]) ); 

        set_skill("move",1000);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}  
void init(){
        ::init();
        add_action("do_look", "look");
}  
int do_look(string arg) {
        if(arg == "drunk"){
                write("һ��ҡͷ���Եĺ��ӣ���Ȼ�Ǻȶ��ˡ�\n");
                write("��������Լ��ʮ���ꡣ\n");
                write("��Ӣ��������ò���˰���\n");
                write("�����Ĳ��ֲ��ݣ��书����������"+HIB"����С��"NOR+"�������ƺ����ᡣ\n");
                write("������"+HIG"���ϲ���˿���˺ۡ�\n"NOR);
                write("��������(Cloth)\n");
                return 1;
        }
        return 0;
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
    else {
        command("sigh");
        command("say ��..... ���Ҿ�....");
    }
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
 
void die() {
        
   object me, ob, owner;
        ob=this_object();
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        
        if (me)
        if(me->query("parrot/���Ӻ�����")) {
                me->set("parrot/����",1);
        }
        ::die();
}  
