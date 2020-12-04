#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[31m����֮��[2;37;0m", ({ "chungou shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[31m������˧֮������֮�ܻӾ����򣬿˵���ʤ��
[2;37;0m����һ�����ޱȼ�Ӳ��[1;36m���꺮����[2;37;0m����[1;33m�����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[31m����֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m �������ޱȼ�̣�����[35m�������[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;36m����[2;37;0m [36mľ[2;37;0m:[1;31m��Ԫ[2;37;0m [32mˮ[2;37;0m:[1;31m��˫[2;37;0m [1;35m��[2;37;0m:[1;31m����[2;37;0m 
[1;37m��[2;37;0m:[1;33m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[1;36m����[2;37;0m ����:[35m��׼[2;37;0m 
����:[1;34m����[2;37;0m ����:[1;32mħ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĽ�ݴ�[2;37;0m ������һЩ�� [1;32m�Ʒ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "wxswlh");
		set("ownername", "Ľ�ݴ�");
		set("value", 36000);
		set("armor_prop/intelligence",36);
		set("armor_prop/strength",0);
		set("armor_prop/karey",32);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 79);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 55);


    set("armor_prop/armor", 405);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 81);
    set("armor_prop/qi", 90);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 8);
    set("armor_prop/damage", 37);

    set("wtypeA",3);
    set("wtypeB",13);
    set("wtypeC",12);
    set("wtypeD",3);
    set("wtypeE",0);
    set("wtypeF",14);
    set("wtypeG",16);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";