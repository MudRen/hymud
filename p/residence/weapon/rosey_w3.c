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
	set_name("[33m������[2;37;0m", ({ "good dagger", "dagger" }));
	set_weight(5982);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
����֮ذ��[2;37;0m����һ���ɷǳ���Ӳ��[31m����ʯ[2;37;0m�Ƴɣ���ʮһ�������Ǯ��[33m����֮ذ��[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ǳ�����������[31m�����ױ�[2;37;0m��������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[1;33m��ʥ[2;37;0m [32mˮ[2;37;0m:[33m�ܸ�[2;37;0m [1;35m��[2;37;0m:[33m�ܸ�[2;37;0m 
[1;37m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
����:[1;33m��ʥ[2;37;0m ����:[36m����[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m���¼�[2;37;0m ������һЩ�� [1;32m�м�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "rosey");
		set("ownername", "���¼�");
		set("value", 9000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",17);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 34);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 34);
    set("weapon_prop/qi", 15);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",10);
    set("wtypeC",4);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",4);
    set("wtypeG",10);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 10);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_dagger(509);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";