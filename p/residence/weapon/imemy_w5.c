// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;32m����֮��[2;37;0m", ({ "haoqi club", "club" }));
	set_weight(12446);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;32m��غ���֮�����ɨħ������Ϊ��Ϊ����֮���ߣ�
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m�Ƴɣ��ض�ʮ�Ľ������Ǯ��[1;32m����֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;34m��������[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;36m����[2;37;0m [1;36m��[2;37;0m:[1;32mħ��[2;37;0m [36mľ[2;37;0m:[1;31m��˫[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [1;37m��[2;37;0m:[1;32mħ��[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ��ʯ:[1;36m����[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[34mϸ��[2;37;0m 
����:[35m��׼[2;37;0m ����:[31m����[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��Ľ[2;37;0m ������һЩ�� [1;32m�Ʒ�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "imemy");
		set("ownername", "��Ľ");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 70);
    set("weapon_prop/parry", 46);
    set("weapon_prop/attack", 29);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 53);
    set("weapon_prop/jing", 60);
    set("weapon_prop/jingli", 60);
    set("weapon_prop/damage", 32);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",12);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
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
	
	init_club(757);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";