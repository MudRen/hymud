#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("Ҷ��", ({ "ye ling", "ye", "ling" }) );
        set("gender", "Ů��");
        set("per", 30);
        set("age", 17);
        set("class", "ghost");
        create_family("����ɽׯ", 3, "����");
        set("combat_exp", 50000);
        set("long",
                "һ������ɫ�·���һ˫������Ĵ��۾������㡣\n"
        );
        set("no_arrest",1);
 set("combat_exp", 9999999);
    set("score", random(90000));
    
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
	set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        map_skill("unarmed", "taiji");
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
             carry_object("/clone/weapon/gangjian")->wield();
} 
void init()
{
        object          me; 
        ::init();
        me = this_player();
        if( interactive(me) && !is_fighting() && !me->is_ghost() ) {
                call_out("greeting", 1, me);
        }
} 
int greeting(object me)
{
        object          groom; 
        if( (string)me->query("family/family_name")=="����ɽׯ" ) {
                message_vision(HIY "\n$N��$n�ȵ����ϵ����Ӹ��߹��㣬������ҵķ��䣡\n"NOR, this_object(), me);
           groom = find_object("/d/ghost/ghost");
                if(!objectp(groom)) groom = load_object("/d/ghost/ghost");
                me->move(groom);
                message_vision(HIY "\n$N��$n���˳�����\n"NOR, me,this_object());
        }
        else {
                if((int)me->query("per")<27 || (string)me->query("gender")!="����") {
                        message_vision(HIY "\n$N��$n�ȵ�������˭�������Ҵ��ҵķ��䣡\n"NOR, this_object(), me);
                        groom = find_object("/d/ghost/ghost");
                        if(!objectp(groom)) groom = load_object("/d/ghost/ghost");
                        me->move(groom);
                        message_vision(HIY "\n$N��$n���˳�����\n"NOR, me,this_object());
                }
                else {
                        message_vision(HIY "\n$N���´����˶�$n���ۣ�˵���������Ժ������ķ����ˣ�û�Ǳ����ܣ�\n"NOR, this_object(), me);
                }
        }
        return 1;
}     
