// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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
	set_name("[31m̫��֮��[2;37;0m", ({ "taie staff", "staff" }));
	set_weight(9290);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m̫������֮������֮�ܺ������£�Ī�в��ӣ�
[2;37;0m����һ���ɾ��Լ�Ӳ��[1;37m����[2;37;0m�Ƴɣ���ʮ�˽�������Ǯ��[31m̫��֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m ���������Է���������[1;31m�������[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;31m��˫[2;37;0m [1;31mħ[2;37;0m:[1;36m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ��Դ:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m ��ʯ:[1;32mħ��[2;37;0m ����:[1;34m����[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",36);
		set("weapon_prop/percao",42);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 94);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 55);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 83);
    set("weapon_prop/jingli", 83);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",12);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 23);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_staff(1522);
	setup();
}



#include "/obj/ritem/weaponzy.h";