#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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
	      set_name("[35m±±¶·Ö®Ñ¥[2;37;0m", ({ "beidou boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
		set("long", @LONG
[35m±±¶·Ö®Ñ¥[2;37;0mÕâÊÇÒ»Ë«ÓÉ¼«Æä¼áÓ²µÄ[1;33m½ðÌú[2;37;0m¼ÓÉÏ[32mÓñ²ÏË¿[2;37;0mÖÆ³É£¬ÖØÁù½ïÈýÁ½ÎåÇ®µÄ[35m±±¶·Ö®Ñ¥[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎÞË«[2;37;0m ¿´ÆðÀ´¼«Æä¼á¹Ì£¬¾ßÓÐ[36m²»Ð¡[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [33mÍÁ[2;37;0m:[1;31mÎÞË«[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ð©·û×Ö£º
¼áÓ²:[1;31m¿ªÔª[2;37;0m ÌìÔ¨:[36m²»´í[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÐ¡Âí[2;37;0m ¡¿¡£ºÍÒ»Ð©¡¾ [1;32mÈ­½Å[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "Ð¡Âí");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",32);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",18);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 164);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 38);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 61);

    set("wtypeA",0);
    set("wtypeB",4);
    set("wtypeC",4);
    set("wtypeD",0);
    set("wtypeE",12);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";