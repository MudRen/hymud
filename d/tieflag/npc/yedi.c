 // zhuzao.c
#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("ҹ��",({"ye di","ye","di"}));
    set("long","���ݹ�������뷢�������������ᣬ\n������������Ʈ�ݣ��ִ���һ�ֲ��ɿ���֮���ϡ�\n");
    set("title","");
    set("gender","����");
    set("no_arrest",1);
    set("age",42);
    set("int",22);
    set("cor",30);
    set("per",30);
    set("cps",20); 
    set("combat_exp",5000000);  
    set("reward_npc", 1);
    set("difficulty", 5);
    set("no_busy",2);
        
    set_skill("ill-quan",150);
    set_skill("force",200);
    set_skill("jiayiforce",150);
    set_skill("unarmed",200);
    set_skill("parry",150);
    set_skill("dodge",150);
    set_skill("tie-steps",150);
    
    set("neili",1000);
    set("max_neili",1000);
    set("mana",1000);
    set("max_mana",1000);
    set("force_factor",50); 
        set("resistance/gin",random(90));
        set("resistance/kee",random(50));
        set("resistance/sen",random(80));
    
    map_skill("force","jiayiforce");
    map_skill("unarmed","ill-quan");
    map_skill("dodge","tie-steps");
    
    set("attitude", "heroism");
    
    set("chat_chance",1);     
    set("chat_msg",({
          "ҹ�ۿ�����Ц��\n",
          }) ); 
    setup();
    carry_object(__DIR__"obj/sicloth")->wear();   
    add_money("gold", random(10));
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
int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    if (me->query_temp("marks/pass_hole_to_yedi") && !query_temp("marks/gived_reward") )
    {
        me->delete_temp("marks/pass_hole_to_yedi"); 
        set_temp("marks/gived_reward",1);
        command("say �㾹���߹��ҵ��Թ������˲���");
    }   
    say ("ҹ��˵�������㿴���Ϸ���ط������𣿡�\n");
    return 1;
}
   
