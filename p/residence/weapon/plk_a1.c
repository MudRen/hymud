#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;33måĞÒ£ÅÛ[2;37;0m", ({ "bad armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
´óÖ®Åû·ç[2;37;0mÕâÊÇÒ»¼şÓÉ¼«Îª¼áÓ²µÄ[32mÇàÍ­[2;37;0m¼ÓÉÏ[1;37mÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÒ»½ï¶şÁ½ÁãÇ®µÄ[1;33m´óÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´¼«Îª¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[33mÍÁ[2;37;0m:[34mÏ¸Ëé[2;37;0m [1;37mÀ×[2;37;0m:[32m´Ö²Ú[2;37;0m [37mÌì[2;37;0m:[32m´Ö²Ú[2;37;0m [40mµØ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;31mÄ§[2;37;0m:[33mºÜ¸ß[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[36m²»´í[2;37;0m ÌìÓî:[33mÒ»°ã[2;37;0m ¸£Ô´:[32m¼«²î[2;37;0m 
¾ø´ú:[32m¼«²î[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
×ÏÊ¯:[33mÒ»°ã[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32måĞÒ£[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÈ­½Å[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "plk");
		set("ownername", "åĞÒ£");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",7);
		set("armor_prop/karey",4);
		set("armor_prop/percao",4);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 10);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 14);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",2);
    set("wtypeF",0);
    set("wtypeG",3);
    set("wtypeH",0);
    set("wtypeI",3);
    set("wtypeJ",6);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 1);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";