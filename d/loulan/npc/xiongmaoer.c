#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("��è��", ({ "xiong maoer","maoer" }) );
        set("gender", "����" );
        set("title", HIR"������һ������"NOR );
        set("long",
        "ֻ���������˳ߣ���ü���ۣ�����б���ű����ʶ̵�����������\nֻ�����ľƺ�«��һ��߸裬һ��ʹ����\n"
                );
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"blade.jichulianhuan":),
                      (:perform_action,"dodge.shenjimiaosuan":),
        }));
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 800000);
        set("force", 1000);
        set("max_force", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 30); 
        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "��è�������߸裺ǧ����������飬�����ԹŶ�Ӣ�ۣ��ҰѺ��г���ƣ�Ƽˮ����һЦ�ꡣ\n",
        "��è���������������˰����ˣ��㵽���������\n",
                }) );
        set("inquiry",  ([
                "����" : "�������˰����ˣ����Ƿ񻹻����˼䣿\n",
                "������" : "�������֪����Ѿͷ����Ϣô������������ô��\n",
                "������" : "�������ô����������ħ�ǣ���\n",
                "�����" : "����������˾���˭��Ц������أ�\n",
                ])); 
       set_skill("dodge", 100);
        set_skill("parry",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 80);
	set_skill("unarmed",60);
	set_skill("demon-steps",200);
	set_skill("demon-strike",200);
	set_skill("demon-force",200);
	set_skill("blade",150);
	set_skill("demon-blade",250);
	set_skill("xuanyuan-axe",550);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("axe","xuanyuan-axe");
	map_skill("parry","demon-blade");

set("pubmaster",1);
        set("max_neili", 25000);
        set("neili", 25000);
        set("force_factor", 30);
	set("max_qi",9999);
        set("max_jing",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("eff_jing",9999);
	set("jing",9999);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
                
        setup();
        carry_object("/d/loulan/obj/blade")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/loulan/obj/winepot");
}       
