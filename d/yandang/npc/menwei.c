#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"ɽׯ����"NOR, ({ "menwei","men wei"}));
	set("gender", "����");
	set("age", 23);

	set("combat_exp", 50000);
	set("shen_type", 1);
       set_skill("unarmed", 200);
	set_skill("sword", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
       set_skill("force", 200);
create_family("�㵴��", 3, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
	
