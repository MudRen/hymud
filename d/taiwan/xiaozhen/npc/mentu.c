#include <ansi.h>
inherit NPC;
void say_some(string word);

void create()
{
    set_name("��ͽ",({"mentu"}));
    set("gender","����");
    set("age",16+random(30));
    set("title",RED"��ڤɽׯ"NOR);
    set("combat_exp",1000+random(10000));
    set("kee",300);
    set("max_kee",300);
    set("force",300);
    set("max_force",300);
    set("force_factor",5);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "��ڤɽׯ":"�����ڴ��ĵط������ˡ�\n",
    "������ħ��":"���������ϴ󷨣���ϧ�缸����ʧ����.\n",
    ]));
        set("shen_type",-1);
    
    set_skill("dodge",4+random(10));
    set_skill("parry",4+random(10));
    set_skill("unarmed",4+random(10));
    set_skill("force",4+random(10));
    set_skill("literate",2);

  
    setup();
    add_money("silver",3);
 }

void say_some(string word)
{
	command("say "+word);
}
   
