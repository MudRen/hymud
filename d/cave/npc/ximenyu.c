#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("������", ({"ximen yu","ximen"}) );
        set("gender", "����" );
        set("nickname", HIC"����ʮ��"NOR);
        set("title", "������ �ֶ����");
        set("long", "һ�ź�˹�ģ��ܺ������װ׾����������������εøɾ������롣������
˫�֣�ʩʩȻ�����ŷ���������������΢Ц���۾�Ҳ��Ц���еء�����
�������Ǹ��ص����ݷ����ѵ���š�\n");
        set("attitude", "friendly");
        set("class","beggar");
        set("age", 45);
        set("cor", 25);
        set("str",36);
        set("cps", 25);
        set("reward_npc", 1);
        set("difficulty", 5);
        set("ill_boss",5);
        set("combat_exp", 4000000);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set("force", 3000);
        set("max_neili", 3000);
        set("force_factor", 100);
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
       
        set("no_busy",4);
        set("resistance/kee",40);
        set("resistance/gin",40+random(50));
        set("resistance/sen",40);     
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "������������Ѫ���еĸ�����˫˫����Ц����˭���������ᣬ������³����ٺ١�\n",
"��������Ц������������Ԫ�գ��عٽ��£����˼��ƶ񣬵�ʿ��������\n����������ͽ����ý��ѡ�\n",
        }) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/stone_5"); 
} 
void killed(object me){
        message_vision("$N�������Ű����Ŵ����������ǹ���૵�����ô���ܡ�����ô���ܣ������� 
����������û��һ�㡣�����ĺ������ˡ����������С���\n", this_object()); 
        call_out("dead", 3, me);
        return;
} 
void dead(object me){
        object gao;
        if(present("gao li", environment()) && present("shuang shuang", environment())){
                gao = present("gao li", environment());
                this_object()->set_temp("last_damage_from",gao);        
                gao->do_leave(me);
        }
        this_object()->die();
}
/*
void die(){
        object *inv, ob, killer;
        int i;
        if(objectp(killer=query_temp("last_damage_from") ))
        if (killer->query("combat_exp")<4000000) {
                ::die();
                return;
                } 
// reason 1, people still get 5 color crystal quest
// reason 2, zombie exp is always high
        inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
           if(ob->query("name")== HIM"��ˮ��"NOR) {
                        destruct(ob);
                }
        }
        ::die();
}
*/   
