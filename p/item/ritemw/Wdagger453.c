// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[31m��Ȫ֮ذ��[2;37;0m", ({ "longquan dagger", "dagger" }));
	set_weight(15803);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m��Ȫ�˼伫Ʒ������������
[2;37;0m����һ�����ޱȼ�Ӳ��[1;37m����[2;37;0m�Ƴɣ�����ʮһ��������Ǯ��[31m��Ȫ֮ذ��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;31m�������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m����[2;37;0m [1;34m��[2;37;0m:[1;31m����[2;37;0m [40m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ��Դ:[32m�ֲ�[2;37;0m 
����:[1;34m����[2;37;0m 


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
		set("weapon_prop/strength",41);
		set("weapon_prop/karey",37);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 80);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",15);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",15);
    set("wtypeI",0);
    set("wtypeJ",10);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 24);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_dagger(1595);
	setup();
}



#include "/obj/ritem/weaponzy.h";