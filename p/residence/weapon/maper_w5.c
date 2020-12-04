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
	set_name("[1;36m������Ԩ[2;37;0m", ({ "fengyun sword", "sword" }));
	set_weight(17333);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;35m��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m�Ƴɣ�����ʮ�Ľ�������Ǯ��[1;35m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;34m��������[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;31m��Ԫ[2;37;0m [1;36m��[2;37;0m:[1;33m��ʥ[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [31m��[2;37;0m:[1;31m����[2;37;0m [33m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��Դ:[34mϸ��[2;37;0m 
��ʯ:[1;36m����[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "��ͼһ��");
		set("value", 25000);
		set("weapon_prop/intelligence",56);
		set("weapon_prop/strength",56);
		set("weapon_prop/karey",56);
		set("weapon_prop/percao",56);
		set("weapon_prop/dexerity",56);
		set("weapon_prop/constitution",56);
    set("weapon_prop/dodge", 73);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 56);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 56);
    
    set("weapon_prop/neili", 56);
    set("weapon_prop/qi", 56);
    set("weapon_prop/jing", 56);
    set("weapon_prop/jingli", 56);
    set("weapon_prop/damage", 0);

    set("wtypeA",7);
    set("wtypeB",9);
    set("wtypeC",7);
    set("wtypeD",14);
    set("wtypeE",8);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",13);
    set("wtypeJ",7);
    set("wtypeK",10);
    set("wtypeL",7);
    

                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(1334);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";