// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WHIP;

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
	set_name("[1;31m����֮��[2;37;0m", ({ "lianyu whip", "whip" }));
	set_weight(13028);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;31m��ʮ�������еأ������гǣ�������ǣ���С��ħ�������������ڴ��ֻ�������ν֮����������
[2;37;0m����һ�����൱��Ӳ��[31m����ʯ[2;37;0m�Ƴɣ��ض�ʮ����������Ǯ��[1;31m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������൱����������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
[1;31mħ[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��Դ:[34mϸ��[2;37;0m 
��Ԩ:[32m�ֲ�[2;37;0m ����:[35m��׼[2;37;0m 
����:[31m����[2;37;0m ��ʯ:[35m��׼[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",31);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",25);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",35);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 53);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 51);
    set("weapon_prop/defense", 64);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",13);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",9);
    

                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_whip(905);
	setup();
}



#include "/obj/ritem/weaponzy.h";