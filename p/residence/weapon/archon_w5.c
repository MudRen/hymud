// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[1;32m����֮��[2;37;0m", ({ "general blade", "blade" }));
	set_weight(5098);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
����֮��[2;37;0m����һ���ɷǳ���Ӳ��[33m����[2;37;0m�Ƴɣ���ʮ��һ����Ǯ��[1;32m����֮��[2;37;0m��
�ۺ�����[31m��������[2;37;0m �������ǳ�����������[32mˮ׼����[2;37;0m��������
������˼����ŷ��ţ�
[1;37m��[2;37;0m:[35m��׼[2;37;0m [40m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
����:[31m����[2;37;0m ����:[33mһ��[2;37;0m ����:[36m����[2;37;0m 
��ʯ:[36m����[2;37;0m ����:[36m����[2;37;0m 

�Լ�һ�Ź�׭�֡� [1;32mʥ��[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "ʥ��");
		set("value", 2000);
		set("weapon_prop/intelligence",8);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 16);
    set("weapon_prop/attack", 14);
    set("weapon_prop/armor", 14);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",6);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
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
	
	init_blade(188);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";