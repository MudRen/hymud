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
	set_name("[31m̫��֮��[2;37;0m", ({ "taie blade", "blade" }));
	set_weight(19535);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m̫������֮������֮�ܺ������£�Ī�в��ӣ�
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m�Ƴɣ�����ʮ�Ž�������Ǯ��[31m̫��֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȷ���������[1;34m��������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m����[2;37;0m [32mˮ[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��Դ:[33m�ܸ�[2;37;0m 
��Ԩ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m ����:[32m�ֲ�[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[1;34m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĳ��[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "hxsd");
		set("ownername", "ĳ��");
		set("value", 36000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",38);
		set("weapon_prop/karey",49);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",42);
		set("weapon_prop/constitution",49);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 42);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 36);
    
    set("weapon_prop/neili", 85);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",15);
    set("wtypeB",0);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",0);
    set("wtypeL",13);
    

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
    set("sharpness", 26);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_blade(702);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";