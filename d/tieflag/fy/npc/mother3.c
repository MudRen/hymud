 inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIW"�ѿ�"NOR, ({ "ke" }) );
        set("gender", "����" );
        set("title",YEL"̽��¥"NOR);
        
        set("age", 32);
        set("str", 5000);
        set("dur",100);
        set("cor", 14);
        set("per", 4);
        set("cps", 29);
        set("int", 25);
        set("no_fly",1);
        set("long", "�ѿͣ�̽��¥��¥���֣���������10�����ӣ�����ѵ���򶷡�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                }) );   
        set("combat_exp", 500000000);
        set("attitude", "friendly");
        set("max_neili", 500);
        set("neili", 500);
        set("force_factor", 10);
        set_skill("parry",151);
        set_skill("dodge",50);
        set_skill("move",50);
        set_skill("unarmed",50); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object who, object ob)
{
        object another;
        object *inv;
        int i,j;
        
        if (who->query("combat_exp")<=3000000) {
                command("say �㻹�Ƕ�������ɡ�");
           return 0;
        }       
        
        inv=all_inventory(environment(this_object()));
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("dungeon_npc")) j++;
        }
        
        if (j>3) {
                command("say �ȴ�����ڳ�����˵��!");
                return 0;
        }
        
        if( ob->value() >= 1000) {
                message_vision("$N˵���ã�����֡�\n",this_object());
                message_vision("$N���𳤵ѣ��ཱུش��˼�����\n",this_object());
                another = new(__DIR__"fightnpc3");
                another->move(environment(this_object()));
                message("vision",another->query("name")+HIG"ͻȻ��������ǰ˵:��������ɱ˭����\n"NOR,environment(this_object()));              
                        return 1;
                } else {
                        command("say ��㣬���ǲ���������\n");
                        return 0;
                }
        return 0;
}  
void die(){
         message_vision("$N΢΢һ��������ɫ�ָֻ��˺���\n", this_object());
        "/cmds/imm/full"->main(this_object(),"");
} 
void init() {
        }    
