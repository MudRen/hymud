#include <ansi.h> 
#include <armor.h>

inherit HEAD;

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
	      set_name("[35m½µÉñÖ®¿ø[2;37;0m", ({ "general head", "head" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶¥");
		set("long", @LONG
ÔÂÁúÖ®Í·¿ø[2;37;0mÕâÊÇÒ»¶¥ÓÉÎŞ±È¼áÓ²µÄ[33mÈíÌú[2;37;0m¼ÓÉÏ[33m´óÂé[2;37;0mÖÆ³É£¬ÖØÈı½ïÈıÁ½ËÄÇ®µÄ[35mÔÂÁúÖ®Í·¿ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[34mÏ¸Ëé[2;37;0m [1;33m½ğ[2;37;0m:[33mºÜ¸ß[2;37;0m [31m»ğ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m [1;35m·ç[2;37;0m:[35m±ê×¼[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
ÉÁµç:[36m²»´í[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·½ÖÛ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "boat");
		set("ownername", "·½ÖÛ");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 14);


    set("armor_prop/armor", 31);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",4);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",8);
    set("wtypeE",5);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",2);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 3);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";