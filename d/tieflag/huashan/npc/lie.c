 inherit NPC;
#include <ansi.h>
void smart_fight(); 
void create()
{
        set_name("����", ({ "li e" }) );
        set("gender", "����");
        set("age", 65);
        set("long",
"���ߴ��ż�Ϊ���µ�˿�����ӣ�����б���ű��������ǽ���ܳ�����������
���ݵ������ϣ������ҵ������ˣ��Ե����ǻ�����Ȼ�������������Ŀ����ӥ��
��֮ȴ��������η��\n"
);
        set("inquiry", ([
        ]) );
      
        set("chat_chance", 1);
        set("chat_msg", ({ 
        }) );
          
        set("attitude", "aggressive");
        set("title",HIW"��Ἵ���"NOR);
        set("bellicosity",400000);
        set("score", 0);
        set("class", "fighter");
        set("reward_npc", 1);
        set("difficulty",10);
        
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",50);
        
        set("neili", 1400);
        set("max_neili",1400);
        set("force_factor", 40);
        set("atman", 500);
        set("max_atman", 500);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",80);     
        
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
          
        set_skill("doomforce", 150);
        set_skill("doomsteps",200);
        set_skill("doomstrike",200);
        set_skill("doomsword",150);
        
        set_skill("kwan-yin-spells",130);
          set_skill("spells", 150);
          map_skill("spells","kwan-yin-spells");  
          
        map_skill("unarmed","doomstrike");
        map_skill("force", "doomforce");
        map_skill("dodge","doomsteps");
        map_skill("move","doomsteps");
        map_skill("parry","doomsword");
        map_skill("sword","doomsword"); 
        setup(); 
        add_money("gold", random(2));
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say( "������Ц��˵���������ˣ�÷ɽ����ɱ�ˣ������ֵ����ˣ�\n");
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie2");
                return;
        }
        who->perform_action("sword.hunranyijian"); 
        return;
}         
