// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[36m����֮��[2;37;0m", ({ "diwang sword", "sword" }));
	set_weight(1765);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[36m����֮��[2;37;0m����һ�����ޱȼ�Ӳ��[1;32m��ʯ[2;37;0m�Ƴɣ�������������Ǯ��[36m����֮��[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȷ���������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[1;34m��[2;37;0m:[1;31m��˫[2;37;0m 
���滹����һЩ���֣�
����:[1;31m��Ԫ[2;37;0m ����:[34mϸ��[2;37;0m ��Ԩ:[34mϸ��[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",27);
		set("weapon_prop/dexerity",25);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 41);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 40);
    set("weapon_prop/jingli", 40);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 13);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(814);
	setup();
}



#include "/obj/ritem/weaponzy.h";