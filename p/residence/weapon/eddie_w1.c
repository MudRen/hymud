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
	set_name("[35m������[2;37;0m", ({ "yuchang sword", "sword" }));
	set_weight(7032);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m�㳦�����ޱȣ��ܿ���ٵأ�������ħ��
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m�Ƴɣ���ʮ�Ľ�������Ǯ��[31m�㳦֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;35m��������[2;37;0m��������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;31m����[2;37;0m [1;33m��[2;37;0m:[1;33m��ʥ[2;37;0m [36mľ[2;37;0m:[1;31m��˫[2;37;0m [32mˮ[2;37;0m:[1;31m����[2;37;0m [33m��[2;37;0m:[1;31m��˫[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ��Ԩ:[33m�ܸ�[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ��ʯ:[1;34m����[2;37;0m ����:[35m��׼[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[1;34m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m������[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "eddie");
		set("ownername", "������");
		set("value", 36000);
		set("weapon_prop/intelligence",46);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",46);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 46);
    set("weapon_prop/parry", 86);
    set("weapon_prop/attack", 72);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 50);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 80);
    set("weapon_prop/jingli", 80);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",12);
    set("wtypeC",14);
    set("wtypeD",9);
    set("wtypeE",12);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",15);
    

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
    set("sharpness", 26);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(932);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";