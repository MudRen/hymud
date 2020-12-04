#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("����", ({"ding gan","ding"}) );
    set("gender", "����" );
    set("nickname", CYN"������"NOR);
    set("title", "������ �̿�");
    set("long", "һ���ܸߴ���ˣ��ߴ����Щӷ�ף���һ˫��ȴ���ɵúܣ�˭�ֻ�֪��
��˫���ɵ��־�����˲Ϣ֮��˺��������ʺ���\n");
        set("class","wolfmount");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("per", 11);
        set("force", 1000);
        set("max_neili", 1000);
        set("force_factor", 50);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("combat_exp", 3000000);
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
	set("max_qi", 18000);
	set("max_jing", 18000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("max_neili", 24000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��������ϸϸ������ָ�ף�Ŀ��ͻȻ¶��һ�ֲп��Ц�ݡ�\n",
        }) ); 
        setup();
        if (!random(5)) carry_object(__DIR__"obj/stone_2");
                else add_money("gold", random(3));
        carry_object(__DIR__"obj/xiuzhiblade");
        carry_object("clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/waternut");
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
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        if (!ob->query("vendetta/authority")){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
   }
        return;
}  
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (enemy[i]->query("qi")>4000)
                        {
                                this_object()->smart_busy();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("unarmed.ningxie");
}
smart_attack() {
        this_object()->perform_action("unarmed.shiden");        
        }    
