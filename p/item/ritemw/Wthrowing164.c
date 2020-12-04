// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[37m��Ȫ֮����[2;37;0m", ({ "general throwing", "throwing" }));
	set_weight(226);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("long", @LONG
��Ȫ֮����[2;37;0m����һ֧��ʮ�ּ�Ӳ��[33m����[2;37;0m�Ƴɣ������������Ǯ��[37m��Ȫ֮����[2;37;0m��
�ۺ�����[31m��������[2;37;0m ������ʮ�ַ���������[36m��С[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[33m�ܸ�[2;37;0m [32mˮ[2;37;0m:[34mϸ��[2;37;0m [1;34m��[2;37;0m:[32m�ֲ�[2;37;0m [1;36m��[2;37;0m:[1;36m����[2;37;0m 
���滹����һЩ���֣�
����:[31m����[2;37;0m ��ʯ:[34mϸ��[2;37;0m ����:[36m����[2;37;0m 


LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 21);
    set("weapon_prop/attack", 17);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",2);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",7);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 6);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	set_amount(1);
	init_throwing(100);
	setup();
}



#include "/obj/ritem/weaponzy.h";