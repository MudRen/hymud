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
	set_name("[1;31m����[2;37;0m", ({ "shentong blade", "blade" }));
	set_weight(16535);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;31m�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
������Ȼ����������࣬������ͣ�磬���绨��������ֶ���
[2;37;0m����һ���ɼ�Ϊ��Ӳ��[37m����[2;37;0m�Ƴɣ�����ʮ����������Ǯ��[1;31m��֮ͨ��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m ��������Ϊ����������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;32mħ��[2;37;0m [1;36m��[2;37;0m:[1;31m��˫[2;37;0m [1;31mħ[2;37;0m:[31m����[2;37;0m [1;33m��[2;37;0m:[35m��׼[2;37;0m [36mľ[2;37;0m:[31m����[2;37;0m [31m��[2;37;0m:[1;34m����[2;37;0m [1;35m��[2;37;0m:[35m��׼[2;37;0m 
[1;37m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ��Ԩ:[34mϸ��[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[31m����[2;37;0m ��ʯ:[1;36m����[2;37;0m ����:[1;36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

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
		set("weapon_prop/intelligence",48);
		set("weapon_prop/strength",48);
		set("weapon_prop/karey",48);
		set("weapon_prop/percao",48);
		set("weapon_prop/dexerity",48);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 70);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 42);
    set("weapon_prop/defense", 69);
    
    set("weapon_prop/neili", 48);
    set("weapon_prop/qi", 72);
    set("weapon_prop/jing", 48);
    set("weapon_prop/jingli", 48);
    set("weapon_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",8);
    set("wtypeE",0);
    set("wtypeF",6);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",12);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "force",
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
	
	init_blade(1302);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";