#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Сͯ",({"xiao tong","xiao"}));
	set("area","Ұ��կ");
	set("long","ר���̺���˯����С�к���\n");
	set("age",25);
        setup();
	carry_object("/clone/misc/cloth.c")->wear();
}
	
