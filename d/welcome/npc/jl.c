
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��ʦ", ({ "jiao tou" }) );
 set("title", HIR "��ݽ���" NOR);
	set("gender", "����" );
	//set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "
���ǹŴ����ݽ���������԰���Ϊʦ��duilian jiao tou����ϰ�书��
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);
        set_skill("literate", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("claw", 150);
        set_skill("hand", 150);
        set_skill("strike", 150);
        set_skill("finger", 150);
        set_skill("feixian-sword", 250);
        set_skill("softsword", 250);
        set_skill("cuff", 150);
        set_skill("blade", 150);
        set_skill("stick", 150);
        set_skill("club", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("throwing", 150);
        set_skill("bat-blade",250);
        set_skill("changquan",250);
        set_skill("jingyiforce",250);
set("skill_public", 1);
set("pubmaster", 1);
set("pubduilian", 1);
	//create_family("�Ŵ�", 1, "����");
        set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 250);



	setup();
	carry_object("clone/cloth/cloth")->wear();
}
