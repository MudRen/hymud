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
	set_name("[1;32m��������[2;37;0m", ({ "moye sword", "sword" }));
	set_weight(14433);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31mĪа�����ޱȣ��ܿ���ٵأ�������ħ��
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m�Ƴɣ��ض�ʮ�˽������Ǯ��[31mĪа֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;35m��������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;33m��ʥ[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [32mˮ[2;37;0m:[1;33m��ʥ[2;37;0m [31m��[2;37;0m:[1;31m��˫[2;37;0m [1;37m��[2;37;0m:[1;35m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ��Ԩ:[33m�ܸ�[2;37;0m ����:[1;32mħ��[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[1;36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����վ[2;37;0m ������һЩ�� [1;32mָ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "����վ");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",43);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 41);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 43);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 94);
    
    set("weapon_prop/neili", 62);
    set("weapon_prop/qi", 38);
    set("weapon_prop/jing", 71);
    set("weapon_prop/jingli", 71);
    set("weapon_prop/damage", 0);

    set("wtypeA",10);
    set("wtypeB",9);
    set("wtypeC",10);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",16);
    set("wtypeL",15);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(968);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";